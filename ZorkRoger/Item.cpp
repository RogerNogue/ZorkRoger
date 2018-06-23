#include "Item.h"



Item::Item(type tp, string namep, string descriptionp, vector<Entity*> containsp, bool hard) :
	Entity(tp, namep, descriptionp, containsp)
{
	hardToSee = hard;
}


Item::~Item()
{
}
