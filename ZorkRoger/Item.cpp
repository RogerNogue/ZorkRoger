#include "Item.h"



Item::Item(string namep, string descriptionp, vector<Entity*> containsp, bool hard) :
	Entity(namep, descriptionp, containsp)
{
	t = ITEM;
	hardToSee = hard;
}


Item::~Item()
{
}
