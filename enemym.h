#ifndef ENEMYM_H
#define ENEMYM_H

#include<string>

using namespace std;

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".
class Room;

class EnemyM
{
public:
    EnemyM();
    ~EnemyM();

    int    getHealth();
    int    getStamina();
    Room  *getCurrentRoom();

    void setHealth(int setHealth);
    void setStamina(int stamina);
    void setCurrentRoom(Room *next);
    void operator-();

private:
    int health;
    int stamina;
    Room *currentRoom;

};

#endif // ENEMYM_H
