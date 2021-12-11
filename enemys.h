#ifndef ENEMYS_H
#define ENEMYS_H

#include<string>

using namespace std;

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".
class Room;

class EnemyS
{
public:
    EnemyS();
    ~EnemyS();

    int    getHealth();
    int    getStamina();
    Room  *getCurrentRoom();

    void setHealth(int setHealth);
    void setStamina(int stamina);
    void setCurrentRoom(Room *next);

private:
    int health;
    int stamina;
    Room *currentRoom;

};

#endif // ENEMYS_H
