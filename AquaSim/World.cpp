#include "stdafx.h"

World::World()
{
}

void World::Init()
{
	// Initiate food grid
	for (int i = 0; i < 5; i++) { for (int j = 0; j < 5; j++) { for (int k = 0; k < 5; k++) { mFoodGrid[i][j][k] = 0.f; } } }
	// Generate 15 food tiles
	for (int i = 0; i < 15; i++) { GenerateFood(); }
}

void World::GenerateFood()
{
	// Position
	int p[3];
	// Generate random position
	for (int i = 0; i < 3; i++) { p[i] = rand() % 5; }
	// Keep generating random position until one is not already filled with food
	while (mFoodGrid[p[0]][p[1]][p[2]] > 0) { for (int i = 0; i < 3; i++) { p[i] = rand() % 5; } }
	// Fill tile with food
	mFoodGrid[p[0]][p[1]][p[2]] = 10.f;
}

bool World::SyncFoodTiles()
{
	int a = 0;
	// Loop through food grid, and add 1 to count for each tile with food
	for (int i = 0; i < 5; i++) { for (int j = 0; j < 5; j++) { for (int k = 0; k < 5; k++) {
		if (mFoodGrid[i][j][k] > 0)
		{
			// Record the data in mFoodTiles
			mFoodTiles[a][0] = i;
			mFoodTiles[a][1] = j;
			mFoodTiles[a][2] = k;
			mFoodTiles[a][3] = mFoodGrid[i][j][k];
			a++;
		}
	} } }
	return a < 15;
}

void World::Update()
{
	// Make sure there are 15 food tiles
	while (SyncFoodTiles()) { GenerateFood(); }
	// Update the former food grid to the current one
	for (int i = 0; i < 5; i++) { for (int j = 0; j < 5; j++) { for (int k = 0; k < 5; k++) { mFormerFoodGrid[i][j][k] = mFoodGrid[i][j][k]; } } }
	// Record food tiles
	std::cout << "Food tiles: " << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "(" << mFoodTiles[i][0] << ", " << mFoodTiles[i][1] << ", " << mFoodTiles[i][2] << ", " << mFoodTiles[i][3] << "), ";
	}
}