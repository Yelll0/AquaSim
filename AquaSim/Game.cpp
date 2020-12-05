#include "Game.h"

Game::Game() {}

void Game::Init()
{
}

void Game::UpdateGame()
{
	// Update Entities
	for (int i = 0; i < mEntities.size(); i++) { mEntities[i]->Update(); }
	// Update World
	mWorld->Update();
}

void Game::RunLoop(int t)
{
	// Update game for given amount of turns
	for (int i = 0; i < t; i++) { UpdateGame(); }
}

