#pragma once
#include "stdafx.h"

class World
{
public:
	World();

	void Init();
	void Update();

	void GenerateFood();
	bool SyncFoodTiles();

	// Getters and Setters
	float GetFoodAtTile(Vector3 t) { int x = t.x, y = t.y, z = t.z; return mFoodGrid[x][y][z]; }
	float GetFormerFoodAtTile(Vector3 t) { int x = t.x, y = t.y, z = t.z; return mFormerFoodGrid[x][y][z]; }
	void EatFoodAtTile(Vector3 t, float f) 
	{ 
		int x = t.x, y = t.y, z = t.z; 
		mFoodGrid[x][y][z] -= f;
	}
	Vector3 GetNearestFood(Vector3 t) 
	{
		float e = 10.f;
		int ind;
		// Loop through mFoodTiles
		for (int i = 0; i < 15; i++)
		{
			// Calculate distance between given point and current food tile
			// c = sqrt(x*x + y*y)
			float c = sqrt(mFoodTiles[i][0]*mFoodTiles[i][0] + mFoodTiles[i][1]*mFoodTiles[i][1]);
			// d = sqrt(c*c + z*z)
			float d = sqrt(c*c + mFoodTiles[i][2]*mFoodTiles[i][2]);
			// Store value if it is less than 
			if (d < e) { e = d; ind = i; }
		}
		// Output the normalized vector between the two points
		Vector3 v = Vector3(mFoodTiles[ind][0], mFoodTiles[ind][1], mFoodTiles[ind][2]) - t;
		v.Normalize();
		return v;
	}

private:
	class Game* mGame;

	// {x, y, z, f} * 15
	float mFormerFoodGrid[5][5][5];
	float mFoodTiles[15][4];
	float mFoodGrid[5][5][5];
};