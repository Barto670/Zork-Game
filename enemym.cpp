#include "enemym.h"
#include<iostream>
#include "eventmanager.h"

EnemyM::EnemyM()
{
    health      = 100;
    stamina     = 100;
    currentRoom = nullptr;
}

EnemyM::~EnemyM()
{
    cout << "/****************** 1. Destructors" << endl;
    delete[] currentRoom;
}

int EnemyM::getHealth()
{
    return health;
}

int EnemyM::getStamina()
{
    return stamina;
}

Room *EnemyM::getCurrentRoom()
{
    return currentRoom;
}

void EnemyM::operator-()
    {
        cout << "/****************** 4. Unary operator overloading" << endl;
        stamina--;
    }


void EnemyM::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
    }

    this->health = health;
}

void EnemyM::setStamina(int stamina)
{
    if (stamina <= 0) {
        stamina = 0;
    }

    this->stamina = stamina;
}

void EnemyM::setCurrentRoom(Room *next)
{
    currentRoom = next;
}
