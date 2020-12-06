#include "stdafx.h"

Entity::Entity(class Game* g, class World* w, float bSp, float bSz, Vector3 p, int pID)
	: mGame(g),
	mWorld(w),
	mSpeed(bSp),
	mSize(bSz),
	mMeta(bSp*bSz*1 /*scalar*/),
	mFoodThresh(bSz*5 /*scalar*/),
	mFood(bSz*5),
	mAge(0),
	mPos(p),
	mID(mGame->GetNextID()),
	mParentID(pID)
{
	// Get nearest tile position
	mTile.x = round(mPos.x);
	mTile.y = round(mPos.y);
	mTile.z = round(mPos.z);
}

void Entity::Update()
{
	// Is at food?
	if (mWorld->GetFoodAtTile(mTile) > 0)
	{
		// Eat food
		Eat();

		// Give birth if there is more food than the animal can hold
		while (mFood > mFoodThresh) { Birth(); }
	} else { Move(); }

	// Consume energy
	mFood -= mMeta / 2;

	// Increase age
	mAge++;

	// Contain in simulated area
	if (mPos.x < 0) { mPos.x = 0; }
	else if (mPos.x > 4) { mPos.x = 4; }
	if (mPos.y < 0) { mPos.y = 0; }
	else if (mPos.y > 4) { mPos.y = 4; }
	if (mPos.z < 0) { mPos.z = 0; }
	else if (mPos.z > 4) { mPos.z = 4; }

	// Get nearest tile position
	mTile.x = round(mPos.x);
	mTile.y = round(mPos.y);
	mTile.z = round(mPos.z);

	// Die if out of food
	if (mFood <= 0) { Die(); }

	std::cout << mTile.x << ", " << mTile.y << ", " << mTile.z << ", Food: " << mFood << ", Age: " << mAge << ", ID: " << mID << ", Parent ID: " << mParentID << std::endl;
}

void Entity::Move()
{
	// Move towards food particle based on speed
	// TODO: Don't overshoot
	mPos += mWorld->GetNearestFood(mPos) * mSpeed;
	// Use energy
	mFood -= mMeta/2;
}

void Entity::Eat()
{
	// Sum of other entities' FoodThreshes
	float sum = 0;
	std::vector<class Entity*> ent = mGame->GetEntitiesAtPos(mTile);
	for (int i = 0; i < ent.size(); i++) { sum += ent[i]->GetFoodThresh(); }
	// Eat the lesser of FoodThresh and FoodAvail * FoodThresh/Sum of other entities' FoodThresh
	float x = mWorld->GetFormerFoodAtTile(mTile) * mFoodThresh / sum;
	if (mFoodThresh < x)
	{
		mWorld->EatFoodAtTile(mTile, mFoodThresh);
		mFood += mFoodThresh;
	}
	else
	{
		mWorld->EatFoodAtTile(mTile, x);
		mFood += x;
	}
}

void Entity::Birth()
{
	// Create a new entity
	// TODO: Vary genes in descendants
	mGame->AddEntity(new Entity(mGame, mWorld, mSpeed, mSize, mPos, mID));
	mFood -= mFoodThresh / 2;
}

void Entity::Die()
{
	// Remove position in entities vector
	mGame->RemoveEntity(mID);
}