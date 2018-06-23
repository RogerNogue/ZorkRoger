#include "Item.h"



Item::Item(string namep, string descriptionp, vector<Entity*> containsp, bool hard, bool lightsp) :
	Entity(namep, descriptionp, containsp)
{
	t = ITEM;
	hardToSee = hard;
	lights = lightsp;
	used = false;
}


Item::~Item()
{
}
