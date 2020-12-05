#pragma once
#include "stdafx.h"

class Game
{
public:
	// Constructor
	Game();
	// Loop functions
	void Init();
	void UpdateGame();
	void RunLoop(int t);

	// Getters and Setters
	std::vector<Entity*> GetEntitiesAtPos(Vector3 t)
	{
		// Output vector
		std::vector<Entity*> ent;
		// Loop through entites
		for (int i = 0; i < mEntities.size(); i++)
		{
			// If the current entity is in the same tile as the one given
			if (mEntities[i]->GetTile().x == t.x && mEntities[i]->GetTile().y == t.y && mEntities[i]->GetTile().z == t.z)
			{
				// Push it to the back of the output vector
				ent.push_back(mEntities[i]);
			}
		}
		return ent;
	}
	int GetTurns() { return mTurns; }

private:
	std::vector<Entity*> mEntities;
	World* mWorld;
	int mTurns;
};	
