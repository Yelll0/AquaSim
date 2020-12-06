#pragma once
#include "stdafx.h"

class Entity
{
public: 
	// Constructor
	Entity(
		class Game* g,
		class World* w,
		// Base values
		// Speed
		float bSp, 
		// Size
		float bSz,
		// Position
		Vector3 p,
		// Parent ID
		int pID
		);

	void Update();

	void Birth();
	void Move();
	void Die();
	void Eat();

	// Getters and Setters
	float GetFood() { return mFood; }
	int GetAge() { return mAge; }
	Vector3 GetPos() { return mPos; }
	Vector3 GetTile() { return mTile; }
	float GetFoodThresh() { return mFoodThresh; }
	int GetID() { return mID; }

private:
	// Game and World
	class Game* mGame;
	class World* mWorld;

	// Non-Inherited Properties
	float mFood;
	int mAge;
	Vector3 mPos;
	Vector3 mTile;

	// Inherited Properties
	float mSpeed;
	float mSize;
	float mMeta;
	float mFoodThresh;
	int mID;
	int mParentID;
};
