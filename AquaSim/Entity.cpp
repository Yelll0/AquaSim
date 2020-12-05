#include "Entity.h"

Entity::Entity(Game* g, World* w, float bSp, float bSz, int x, int y, int z)
	: mGame(g),
	mWorld(w),
	mSpeed(bSp),
	mSize(bSz),
	mMeta(mSize*mSpeed*1/*scalar*/),
	mFoodThresh(mSize*1/*scalar*/),
	mFood(mFoodThresh),
	mAge(0),
	mPos(Vector3(x, y, z))
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
	// Move towards nearest food
	// Check if there is no food left
	if (mFood <= 0)
	{
		// Die
		return;
	}
	// Round position to tile position
	// Is at food?
	if (true /*Whether its tile is food*/)
	{
		// Is EatThresh < FoodAvail * FoodThresh/Sum of other entities' FoodThresh?
		if (mFoodThresh < 1 /*FoodAvail * FoodThresh/Sum of other entities' FoodThresh*/)
		{
			// Eat FoodThresh
		}
		else
		{
			// Eat FoodAvail * FoodThresh/Sum of other entities' FoodThresh
		}
		if (mFood > mFoodThresh)
		{
			// Give Birth
		}
	}
	return;
}

void Entity::Birth()
{

}

void Entity::Move()
{

}