#ifndef ATTACKLISTENER_H
#define ATTACKLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the Teleport command
class AttackListener : public EventListener
{
public:
    AttackListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // ATTACKLISTENER_H
