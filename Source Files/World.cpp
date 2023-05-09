#include "World.h"

World::~World()
{
	for (auto object : m_objects)
	{
		delete(object);
	}
	m_objects.clear();

}
void World::Step(float dt)
{
	for (auto object : m_objects)
	{
		object->Step(dt);
	}
}
void World::Draw(Graphics* graphics)
{
	for (auto object : m_objects)
	{
		object->Draw(graphics);
	}
}
void World::AddPhysicsObject(PhysicsObject* po)
{
	m_objects.push_back(po);
}
void World::RemovePhysicsObject(PhysicsObject* po)
{
	m_objects.remove(po);
}