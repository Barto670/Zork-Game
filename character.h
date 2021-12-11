#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>

using namespace std;

// No need to include room since we're only working with pointers.
// This is how we tell the compiler "there will be a room eventually".
// This is called a "forward declaration".
class Room;

class Character
{
public:
    Character(string name, int stamina, int hunger, int weaponAttacks);
    ~Character();

    string getName();
    int    getHealth();
    int    getStamina();
    Room  *getCurrentRoom();
    int    getHunger();
    int    getWeaponAttacks();

    void setName(string name);
    void setHealth(int setHealth);
    void setStamina(int stamina);
    void setWeaponAttacks(int weaponAttacks);
    void setHunger(int hunger);
    void setCurrentRoom(Room *next);
    bool itemCursed;
    bool itemKey;
    bool itemPotion;
    void operator-();

private:
    string name;
    int health;
    int stamina;
    Room *currentRoom;
    int hunger;
    int weaponAttacks;

};

#endif // CHARACTER_H
