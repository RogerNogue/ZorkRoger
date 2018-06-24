#include "Item.h"



Item::Item(string namep, string descriptionp, vector<Entity*> containsp, bool hard, bool lightsp, bool canBeUsedp, string descriptionUsedp, bool canBeGrabbedp) :
	Entity(namep, descriptionp, containsp)
{
	descriptionUsed = descriptionUsedp;
	canBeGrabbed = canBeGrabbedp;
	t = ITEM;
	hardToSee = hard;
	lights = lightsp;
	used = false;
}


Item::~Item()
{
}
