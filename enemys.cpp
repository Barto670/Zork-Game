#include "enemys.h"
#include<iostream>
#include "eventmanager.h"

EnemyS::EnemyS()
{
    health      = 100;
    stamina     = 100;
    currentRoom = nullptr;
}

EnemyS::~EnemyS()
{
    cout << "/****************** 1. Destructors" << endl;
    delete[] currentRoom;
}

int EnemyS::getHealth()
{
    return health;
}

int EnemyS::getStamina()
{
    return stamina;
}

Room *EnemyS::getCurrentRoom()
{
    return currentRoom;
}


void EnemyS::setHealth(int health)
{
    if (health <= 0) {
        health = 0;
    }

    this->health = health;
}

void EnemyS::setStamina(int stamina)
{
    if (stamina <= 0) {
        stamina = 0;
    }

    this->stamina = stamina;
}

void EnemyS::setCurrentRoom(Room *next)
{
    currentRoom = next;
}
