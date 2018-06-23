#include "Entity.h"



Entity::Entity(type tp, string namep, string descriptionp, vector<Entity*> containsp)
{
	t = tp;
	name = namep;
	description = description;
	contains = containsp;
}


Entity::~Entity()
{
}

void Entity::Update() {

}