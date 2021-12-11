#include "character.h"
#include<iostream>
#include "eventmanager.h"

Character::Character(string name, int stamina, int hunger, int weaponAttacks)
{
    this->name  = name; // We need to use "this->" to differentiate between the "name" argument and the "name" from the class.
    //this->health      = health;
    this->stamina     = stamina;
    this->hunger      = hunger;
    this->weaponAttacks      = weaponAttacks;
    currentRoom = nullptr;
    itemCursed = false;
    itemPotion = false;
    itemKey = false;
}

Character::~Character(){
    cout << "/****************** 1. Destructors" << endl;
    delete[] currentRoom;
}

string Character::getName()
{
    return name;
}

int Character::getHealth()
{
    return health;
}

int Character::getStamina()
{
    return stamina;
}

int Character::getHunger()
{
    return hunger;
}

int Character::getWeaponAttacks()
{
    return weaponAttacks;
}

Room *Character::getCurrentRoom()
{
    return currentRoom;
}


void Character::setName(string name)
{
    this->name = name;
}

void Character::operator-()
    {
        stamina--;
    }

void Character::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->health = health;
}

void Character::setWeaponAttacks(int weaponAttacks)
{

    this->weaponAttacks = weaponAttacks;
}

void Character::setHunger(int hunger)
{

    this->hunger = hunger;
}

void Character::setStamina(int stamina)
{
    if (stamina <= 0) {
        stamina = 0;
        EventManager::getInstance().trigger("characterDeath", this);
    }

    this->stamina = stamina;
}

void Character::setCurrentRoom(Room *next)
{
    currentRoom = next;
}
