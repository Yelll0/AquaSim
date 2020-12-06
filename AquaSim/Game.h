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
	void RunLoop();

	// Getters and Setters
	std::vector<class Entity*> GetEntitiesAtPos(Vector3 t)
	{
		// Output vector
		std::vector<class Entity*> ent;
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
	void AddEntity(class Entity* e) { mEntities.push_back(e); }
	void RemoveEntity(int id) { for (size_t i = 0; i < mEntities.size(); i++) { if (mEntities[i]->GetID() == id) { mEntities.erase(mEntities.begin()+i); break; } } }
	int GetNextID() { mCurrID++; return mCurrID; }

private:
	std::vector<class Entity*> mEntities;
	class World* mWorld;
	int mTurns;
	int mCurrID;
};	
