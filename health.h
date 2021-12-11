#ifndef HEALTH_H
#define HEALTH_H

#endif // Health_H

#include<iostream>

using namespace std;

class Health {
public:
    int hp;
    Health()
    {
        this->hp = 0;
    }

    Health(int hp)
    {
        this->hp = hp;
    }

    Health operator+(Health& h2) // Call by reference
    {
        cout << "/****************** 5. Binary operator overloading" << endl;
        Health h3;
        this->hp = h3.hp + h2.hp;
        h3.hp = this->hp+ h2.hp;
        h3 = h3.hp + h2.hp;
        return h3;
    }
};
