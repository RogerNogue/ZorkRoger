#include "Entity.h"



Entity::Entity(string namep, string descriptionp, vector<Entity*> containsp)
{
	name = namep;
	description = descriptionp;
	contains = containsp;
}


Entity::~Entity()
{
}

void Entity::Update() {

}