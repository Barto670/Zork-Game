#include "curseditemlistener.h"
#include<iostream>
#include "game.h"
#include "eventmanager.h"


CursedItemListener::CursedItemListener(Game *game)
{
    this->game = game;
}

void CursedItemListener::run(void *)
{
    game->cursedItem();
}


