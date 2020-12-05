#include "World.h"

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

void World::Update()
{
	// Make sure there are 15 food tiles
	while (!IsFifteenFood()) { GenerateFood(); }
}