#include "ParticleTest.h"
#include "../Physics/Body.h"
#include "../Physics/CircleShape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}


void ParticleTest::Update()
{
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(1, 3);
		float size = randomf(0.1f, 0.8f);

		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), position, velocity, size);
		body->damping = 0.4f;
		body->gravityScale = 1;
		body->restitution = 0;

		m_world->AddBody(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
}

