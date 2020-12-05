#pragma once
#include "stdafx.h"

class World
{
public:
	World();

	void Init();
	void Update();

	void GenerateFood();

	// Getters and Setters
	float GetFoodAtTile(Vector3 t) { int x = t.x, y = t.y, z = t.z; return mFoodGrid[x][y][z]; }
	void EatFoodAtTile(Vector3 t, float f) { int x = t.x, y = t.y, z = t.z; mFoodGrid[x][y][z] -= f; if (mFoodGrid[x][y][z] < 0) { std::cout << "subzero food value"; } }
	bool IsFifteenFood() 
	{
		int a = 0;
		// Loop through food grid, and add 1 to count for each tile with food
		for (int i = 0; i < 5; i++) { for (int j = 0; j < 5; j++) { for (int k = 0; k < 5; k++) { if(mFoodGrid[i][j][k] > 0) a++; } } }
		return a == 15;
	}

private:
	Game* mGame;

	float mFoodGrid[5][5][5];
};

