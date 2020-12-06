#include "stdafx.h"

Game::Game() {}

void Game::Init()
{
	// Create world
	mWorld = new World();
	mWorld->Init();
	// Create 2 fish
	AddEntity(new Entity(this, mWorld, 1, 1, Vector3(3, 2, 3), NULL));
	AddEntity(new Entity(this, mWorld, 1, 1, Vector3(1, 1, 4), NULL));

	mTurns = 20;
	mCurrID = 1;
}

void Game::UpdateGame()
{
	std::cout << "Entities: " << std::endl;
	// Update Entities
	for (int i = 0; i < mEntities.size(); i++) { 
		mEntities[i]->Update();
	}
	// Update World
	mWorld->Update();
	std::cout << std::endl;
}

void Game::RunLoop()
{
	// Update game for given amount of turns
	for (int i = 0; i < mTurns; i++) { UpdateGame(); }
}

