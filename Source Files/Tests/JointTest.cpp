#include "JointTest.h"
#include "../Physics/Joint.h"
#include "../Physics/CircleShape.h"
#include "../Physics/World.h"
#include "../Physics/Body.h"

#define SPRING_STIFFNESS	100
#define SPRING_LENGTH		1
#define BODY_DAMPING		10
#define CHAIN_SIZE			3


void JointTest::Initialize()
{
    Test::Initialize();
    //                                   smol                    zero this
    m_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
    m_world->AddBody(m_anchor);

    auto prevBody = m_anchor;
    //                                    smol                   more zero
    auto body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
    //man fetch that gravity scale
    body->damping = BODY_DAMPING;
    m_world->AddBody(body);

    auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
    m_world->AddJoint(joint);

    prevBody = body;

    std::vector<Body*> chain1;
    chain1.push_back(body);


    for (int i = 0; i < CHAIN_SIZE; i++)
    {
        body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
        //no more gravity scale
        body->damping = BODY_DAMPING;
        m_world->AddBody(body);

        joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
        m_world->AddJoint(joint);

        prevBody = body;
        chain1.push_back(body);
    }
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld( m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
