#pragma once
#include "stdafx.h"

int main()
{
    Game game;
    game.Init();
    game.RunLoop(game.GetTurns());
    return 0;
}