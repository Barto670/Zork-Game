#ifndef RESTLISTENER_H
#define RESTLISTENER_H

#include "eventlistener.h"

class Game;

// A listener for the Teleport command
class RestListener : public EventListener
{
public:
    RestListener(Game *game);
    void run(void *args) override;
private:
    Game *game;
};

#endif // SLEEPLISTENER_H
