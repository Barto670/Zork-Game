#ifndef SIGN_H
#define SIGN_H

#endif // SIGN_H

#include<string>
#include<iostream>

using namespace std;

class Sign
{
   string x = "Go back and find a key.";
public:
    virtual void fun() = 0;
    string getX() {
        return x;
    }
};

class Derived: public Sign
{
public:
    void fun() {
        cout << "/****************** 8. Abstract classes and pure virtual functions" << endl;
        cout << "Sign: ";
    }
};
