#ifndef CURSEDITEMLISTENER_H
#define CURSEDITEMLISTENER_H

#include "eventlistener.h"
class Game;

class CursedItemListener : public EventListener
{
public:
    CursedItemListener(Game *game);
    void run(void* args) override;;

private:
    Game *game;
};

#endif // CURSEDITEMLISTENER_H
