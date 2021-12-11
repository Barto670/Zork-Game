#ifndef GAME_H
#define GAME_H

#include<string>
#include<vector>

#include "character.h"
#include "enemym.h"
#include "enemys.h"
#include "room.h"
#include "sign.h"

using namespace std;

class Game
{
public:
    Game();
    void reset(bool show_update = false);

    void map();
    void info();
    void go(string direction);
    void teleport();
    void take();
    void cursedItem();
    void attack();

    void update_screen();

    Character &getPlayer();
    EnemyM &getEnemy();
    void setOver(bool over);
    bool is_over();
    void setCurrentRoom(Room *next);
    string mapPlayer(string temp[]);
    string mapEnemy(string temp[]);
    void enemyGo();
    void rest();
    void health();
    void projectDistplay();

private:
    Character      player;
    EnemyM         enemyM;
    EnemyS         enemyS;
    vector<Room *> rooms;
    bool           gameOver;
    bool itemInRoomF = true; // A cursed item
    bool itemInRoomA = true; // A key
    bool itemInRoomI = true; // A potion
    bool talked = false;
};
#endif // GAME_H
