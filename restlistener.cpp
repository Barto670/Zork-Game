#include "restlistener.h"

#include "game.h"

RestListener::RestListener(Game *game)
{
    this->game = game;
}

void RestListener::run(void *)
{
    if (game->is_over()) {
        return;
    }

    this->game->rest();
}
