#pragma once
#include "stdafx.h"

class Entity
{
public: 
	// Constructor
	Entity(
		Game* g,
		World* w,
		// Base values
		// Speed
		float bSp, 
		// Size
		float bSz,
		// Position
		int x, int y, int z
		);
	~Entity();

	void Update();

	void Birth();
	void Move();

	// Getters and Setters
	float GetFood() { return mFood; }
	float SetFood(float f) { mFood = f; }
	int GetAge() { return mAge; }
	Vector3 GetPos() { return mPos; }
	Vector3 GetTile() { return mTile; }

private:
	// Game and World
	Game* mGame;
	World* mWorld;

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
};

