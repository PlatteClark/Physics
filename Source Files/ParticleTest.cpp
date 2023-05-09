#include "ParticleTest.h"
#include "CircleShape.h"
#include <iostream>

void ParticleTest::Initialize()
{
	Test::Initialize();
}


void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);
		auto po = new PhysicsObject(new Body(m_input->GetMousePosition(), velocity), new CircleShape(randomf(10), { randomf(), randomf(), randomf(), 1 }));
		m_world->AddPhysicsObject(po);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->TimeDelta());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
}

