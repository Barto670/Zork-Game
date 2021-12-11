#include "game.h"

#include<ctime>
#include<iostream>

#include "eventmanager.h"

#include "golistener.h"
#include "maplistener.h"
#include "infolistener.h"
#include "restartlistener.h"
#include "teleportlistener.h"
#include "exitlistener.h"
#include "characterdeathlistener.h"
#include "enterroomlistener.h"
#include "victorylistener.h"
#include "defeatlistener.h"
#include "takelistener.h"
#include "curseditemlistener.h"
#include "attacklistener.h"
#include "restlistener.h"
#include "shape.h"
#include "health.h"
#include "npc.h"

template <class T, class U>
T GetMin (T a, U b) {
  return (a<b?a:b);
}

template <class T, class U>
T GetMax (T a, U b) {
  return (a>b?a:b);
}


Game::Game() : player("Hero",100,5,1)
{
    cout << "/****************** 9. Initializer list" << endl;
    srand(time(nullptr
               ));

    // Commands
    EventManager::getInstance().listen("go",        new GoListener(this));
    EventManager::getInstance().listen("map",       new MapListener(this));
    EventManager::getInstance().listen("info",      new InfoListener(this));
    EventManager::getInstance().listen("restart",   new RestartListener(this));
    EventManager::getInstance().listen("teleport",  new TeleportListener(this));
    EventManager::getInstance().listen("exit",      new ExitListener(this));
    EventManager::getInstance().listen("take",      new TakeListener(this));
    EventManager::getInstance().listen("attack",      new AttackListener(this));
    EventManager::getInstance().listen("rest",      new RestListener(this));


    // State changes
    EventManager::getInstance().listen("characterDeath", new CharacterDeathListener(this));
    EventManager::getInstance().listen("enterRoom",      new EnterRoomListener(this));
    EventManager::getInstance().listen("victory",        new VictoryListener(this));
    EventManager::getInstance().listen("defeat",         new DefeatListener(this));
    EventManager::getInstance().listen("cursed",     new CursedItemListener(this));

    rooms.push_back(new Room("A")); // 0
    rooms.push_back(new Room("B")); // 1
    rooms.push_back(new Room("C")); // 2
    rooms.push_back(new Room("D")); // 3
    rooms.push_back(new Room("E")); // 4
    rooms.push_back(new Room("F")); // 5
    rooms.push_back(new Room("G")); // 6
    rooms.push_back(new Room("H")); // 7
    rooms.push_back(new Room("I")); // 8
    rooms.push_back(new Room("J")); // 9

    //                 N         E         S         W
    rooms[0]->setExits(nullptr,  rooms[1], nullptr,  nullptr);  // A
    rooms[1]->setExits(nullptr,  rooms[2], rooms[4], rooms[0]); // B
    rooms[2]->setExits(nullptr,  nullptr,  nullptr,  rooms[1]); // C
    rooms[3]->setExits(nullptr,  rooms[4], nullptr,  nullptr);  // D
    rooms[4]->setExits(rooms[1], rooms[5], rooms[7], rooms[3]); // E
    rooms[5]->setExits(nullptr,  nullptr,  nullptr,  rooms[4]); // F
    rooms[6]->setExits(nullptr,  rooms[7], nullptr,  nullptr);  // G
    rooms[7]->setExits(rooms[4], rooms[8], rooms[9], rooms[6]); // H
    rooms[8]->setExits(nullptr,  nullptr,  nullptr,  rooms[7]); // I
    rooms[9]->setExits(rooms[7], nullptr,  nullptr,  nullptr);  // K

    reset();
}

void Game::projectDistplay(){
   cout << "/****************** 1. Destructors" << endl;
   cout << "/****************** 2. Inheritance (including virtual methods) and cascading constructors" << endl;
   cout << "/****************** 3. Templates" << endl;
   cout << "/****************** 4. Unary operator overloading" << endl;
   cout << "/****************** 5. Binary operator overloading" << endl;
   cout << "/****************** 6. Friends" << endl;
   cout << "/****************** 7. Virtual functions and polymorphism" << endl;
   cout << "/****************** 8. Abstract classes and pure virtual functions" << endl;
   cout << "/****************** 9. Initializer list" << endl;
   cout << "/****************** 10. Dynamic and static dispatch" << endl;
}

void Game::reset(bool show_update)
{
    gameOver = false;

    player.setCurrentRoom(rooms[4]);
    enemyM.setCurrentRoom(rooms[2]);
    enemyS.setCurrentRoom(rooms[8]);

    cout << "Welcome to Zork!" << endl;
    cout << "Winning conditions:" << endl;
    cout << "-Defeat all the enemies on the level" << endl;
    cout << "-Find a key" << endl;
    cout << "-Open the door and enter the victory room" << endl;
    cout << "" << endl;
    cout << "Losing conditions:" << endl;
    cout << "-Health reaches 0" << endl;
    cout << "-Stamina reaches 0" << endl;
    cout << "" << endl;
    cout << "You can 'rest' to regenerate Stamina and Weapon Attacks" << endl;
    cout << "Type 'info' for more commands" << endl;
    cout << "" << endl;

    string Name = "";
    cout << "What is your name?" << endl;
    cout << "----->" ;
    cin >> Name;
    player.setName(Name);

    health();

    cout << "Player Name:  " << player.getName() << endl;
    if (show_update) {
        update_screen();
    }

    cout << "/****************** 3. Templates" << endl;
    //Min and Max display
    int i=0, j=100, k, n;
    int u=0, o=100, v, b;
    k=GetMin(i,j);
    n=GetMax(i,j);
    cout <<""<< endl;
    cout <<"Min Health: "<< k << endl;
    cout <<"Max Health "<< n << endl;
    cout <<""<< endl;
    v=GetMin(u,o);
    b=GetMax(u,o);
    cout <<"Min Stamina: "<< v << endl;
    cout <<"Max Stamina "<< b << endl;
    cout <<""<< endl;




}

void Game::setOver(bool over)
{
    this->gameOver = over;
}

void Game::map()
{

    /*cout << "A-B-C" << endl;
    cout << "  |  " << endl;
    cout << "D-E-F" << endl;
    cout << "  |  " << endl;
    cout << "G-H-I" << endl;
    cout << "  |  " << endl;
    cout << "  K  " << endl;*/

    Room *currentRoom = player.getCurrentRoom();
    Room *currentRoom2 = enemyM.getCurrentRoom();
    Room *currentRoom3 = enemyS.getCurrentRoom();

    string roomLocation[3][3] = {{"A", "B" ,"C"} ,{"D" ,"E" , "F"} , {"G" , "H" , "I"}};

    cout << "" << endl;
    cout << "[x] is where you are located" << endl;
    cout << "!x! is where enemies are located" << endl;
    cout << "[!x!] is if an enemy and a player are in the same room" << endl;
    cout << "" << endl;
    cout << "Map:" << endl;
    cout << ""<< endl;

    for(int i = 0; i <= 2; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            if((currentRoom->getName() == roomLocation[i][j] && currentRoom2->getName() == roomLocation[i][j] && enemyM.getHealth() > 0) || (currentRoom->getName() == roomLocation[i][j] && currentRoom3->getName() == roomLocation[i][j] && enemyS.getHealth() > 0))
            {
                cout << "[!";
                cout << roomLocation[i][j];
                cout << "!]";
            }else if((roomLocation[i][j] == currentRoom2->getName()  && enemyM.getHealth() > 0 ) || (roomLocation[i][j] == currentRoom3->getName() && enemyS.getHealth() > 0 ))
            {
                cout << " !";
                cout << roomLocation[i][j];
                cout << "! ";
            }else if(roomLocation[i][j] == (currentRoom->getName()) )
            {
                cout << " [";
                cout << roomLocation[i][j];
                cout << "] ";
            }else
            {
                cout << "  ";
                cout << roomLocation[i][j];
                cout << "  ";
            }
            if(j < 2){
                cout << "-";
            }

        }
        cout << ""<< endl;
        cout << "        |        " << endl;

    }
    cout << "        K        " << endl;
    cout << "" << endl;
}



void Game::info()
{
    cout << "Available commands:" << endl;
    cout << ""                    << endl;
    cout << "go <direction>"      << endl;
    cout << "teleport"            << endl;
    cout << "map"                 << endl;
    cout << "info"                << endl;
    cout << "take"                << endl;
    cout << "attack"              << endl;
    cout << "rest"               << endl;
}

void Game::attack(){
    Room *currentRoom = player.getCurrentRoom();
    Room *currentRoom2 = enemyM.getCurrentRoom();
    Room *currentRoom3 = enemyS.getCurrentRoom();

    if(player.getWeaponAttacks() >= 1)
    {
        if(currentRoom->getName() == (currentRoom2->getName())){
            enemyM.setHealth(0);
            cout << "You attacked the enemy. And you killed it"<< endl;
            player.setWeaponAttacks(player.getWeaponAttacks() - 1);
        }else if(currentRoom->getName() == (currentRoom3->getName())){
            enemyS.setHealth(0);
            cout << "You attacked the enemy. And you killed it"<< endl;
            player.setWeaponAttacks(player.getWeaponAttacks() - 1);
        }else{
            cout << "No enemies to attack"<< endl;
        }
    }else{
        cout << "No weapon attacks left, try to 'rest' to restore some"<< endl;
    }
}


void Game::health(){
    Health h1(0);
    Health h2(100);
    Health h3(0);


    h3.operator+(h2);

    cout << "Health:" <<h3.hp<< endl;
    player.setHealth(h3.hp);

}

void Game::go(string direction)
{
    if(player.getHunger() > 0){
    Room *currentRoom = player.getCurrentRoom();
    if(direction == "south" && player.itemKey == false && (currentRoom->getName() == "H")){
        Derived d;
        d.fun();
        cout <<d.getX()<< endl;
        cout << "You Don't have a key to enter this room" << endl;

    }else
    {
        Room *next = player.getCurrentRoom()->getExit(direction);
        if (next != nullptr) {
            player.setCurrentRoom(next);
            -player;
            EventManager::getInstance().trigger("enterRoom", next);
            player.setHunger(player.getHunger() - 1);
            enemyGo();


    }else
    {
        cout << "You hit a wall" << endl;
    }
    }
    }else{
        cout << "You have no energy to move, you need to rest" << endl;
    }
}

void Game::enemyGo(){
    Room *currentRoom2 = enemyM.getCurrentRoom();
    if(currentRoom2 != nullptr)
    {
        bool loop = true;
        while(loop == true)
        {
            int rng = rand() % 4 + 1;
            string direction = "";

            if(rng == 1){
                direction = "north";
            }else if (rng == 2){
                direction = "east";
            }else if (rng == 3){
                direction = "south";
            }else if (rng == 4){
             direction = "west";
        }
        Room *next1 = enemyM.getCurrentRoom()->getExit(direction);

        if (next1 != nullptr)
        {
            enemyM.setCurrentRoom(next1);
            -enemyM; // stamina --;
            loop = false;
        }
        }
    }
}

void Game::rest(){
    int rng = rand() % 20 + 1;
    if(rng >= 1 && rng <= 10)
    {
        cout << ""<< endl;
        cout << "You fell asleep but you were attacked by monsters"<< endl;
        cout << "You feel dizzy and you lose ";
        cout << rng;
        cout << " hp and stamina";
        cout << ""<< endl;
        player.setStamina(player.getStamina() - rng);
        player.setHealth(player.getHealth() - rng);
    }else{   
        cout << ""<< endl;
        cout << "You fell asleep and it was a peaceful night and you are now fully rested"<< endl;
        cout << "You ate some food when u woke up and you are ready to continue your journey"<< endl;
        cout << "Your stamina is maxed out"<< endl;
        cout << "You gain another weapon attack"<< endl;
        cout << ""<< endl;
        player.setStamina(100);
        player.setWeaponAttacks(player.getWeaponAttacks() + 1);
        player.setHunger(5);

    }
}

void Game::teleport()
{
    int selected = rand() % rooms.size();
    player.setCurrentRoom(rooms[selected]);
    player.setStamina(player.getStamina() - 50);
    EventManager::getInstance().trigger("enterRoom", rooms[selected]);
}

void Game::take()
{
Room *currentRoom = player.getCurrentRoom();
    if((currentRoom->getName() == "F") && itemInRoomF == true)
    {

        cout << "You search the room and you managed to take 'A cursed item' "<< endl;
        cout << "You start to feel dizzy..."<< endl;
        cout << "You wake up tired after an hour with less health and stamina"<< endl;
        itemInRoomF = false;
        player.itemCursed = true;
        EventManager::getInstance().trigger("cursed");

    }
    else if((currentRoom->getName() == "A") && itemInRoomA == true)
    {
        cout << "You search the room and you managed to take 'A key' "<< endl;
        cout << "This key must open some door..."<< endl;
        itemInRoomA = false;
        player.itemKey = true;
    }
    else if((currentRoom->getName() == "I") && itemInRoomI == true)
    {
        cout << "You search the room and you managed to take 'A potion' "<< endl;

        player.setStamina(100);
        itemInRoomI = false;
        player.itemPotion = true;


        cout << "/****************** 7. Virtual functions and polymorphism" << endl;
        //random potion size
        int rng = rand() + 1;
        int x = rand() + 10;
        int y = rand() + 10;
        Shape *shape;
        Rectangle rec(x,y);
        Triangle  tri(x,y);
        if(rng == 0){
            shape = &rec;
            cout << "The potion you picked up was in the shape of a rectangle"<< endl;
            cout << rec.area()  <<" ml"<< endl;
        }else{
            shape = &tri;
            cout << "The potion you picked up was in the shape of a triangle"<< endl;
            cout << tri.area()  <<" ml"<< endl;
        }
        cout << "The potion regenerated your stamina fully"<< endl;


    }else{
        cout << ""<< endl;
        cout << "You can't take anything because there is no items here"<< endl;
    }

}

void Game::cursedItem(){
    player.setHealth(player.getHealth() - 25);
    player.setStamina(player.getStamina() - 25);
    player.itemCursed = false;
}

bool Game::is_over()
{
    return gameOver;
}

Character &Game::getPlayer()
{
    return player;
}

void Game::update_screen()
{
    if (!gameOver) {
        Room *currentRoom = player.getCurrentRoom();

        cout << endl;
        cout << "You are in " << currentRoom->getName() << endl;


        cout << "Exits:";
        if (currentRoom->getExit("north") != nullptr) { cout << " north"; }
        if (currentRoom->getExit("east")  != nullptr) { cout << " east";  }
        if (currentRoom->getExit("south") != nullptr && currentRoom->getName() == "H" && player.itemKey == true) { cout << " south"; }
        else if (currentRoom->getExit("south") != nullptr && currentRoom->getName() != "H") { cout << " south"; }
        if (currentRoom->getExit("west")  != nullptr) { cout << " west";  }
        cout << endl;

        //Weapon attacks print
        cout << "Weapon attacks left (" << player.getWeaponAttacks() << ")"<< endl;

        //Player HP and Stamina/ enemy HP and Stamina
        cout << player.getName() <<":  HP: " << player.getHealth() << " ST: " << player.getStamina() << " Hunger: " << player.getHunger() << endl;
        if(player.getCurrentRoom() == enemyM.getCurrentRoom() && enemyM.getHealth() > 0){
            cout << "EnemyM:  HP: " << enemyM.getHealth() << " ST: " << enemyM.getStamina() << endl;
            cout << "You can attack the enemy by typing 'attack' " << endl;
        }else if(player.getCurrentRoom() == enemyS.getCurrentRoom() && enemyS.getHealth() > 0){
            cout << "EnemyS:  HP: " << enemyS.getHealth() << " ST: " << enemyS.getStamina() << endl;
            cout << "You can attack the enemy by typing 'attack' " << endl;
        }

        if((currentRoom->getName() == "F") && itemInRoomF == true){
            NPC adventurer;
            cout << "/****************** 6. Friends" << endl;
            if(talked == false){
                adventurer.setText("Hello my name is Steven. Im wandering around these caves for a few months now");
                talked = true;
            }else{
                adventurer.setText("Hello my name is Steven. You already know that.... We have talked already");
            }
            printText( adventurer );
            cout << "Item in room : A suspicious item (type 'take' to pick it up)"<< endl;
        }
        else if((currentRoom->getName() == "A") && itemInRoomA == true){
            cout <<  "Item in room : A key (type 'take' to pick it up)"<< endl;
        }
        else if((currentRoom->getName() == "I") && itemInRoomI == true){
            cout <<  "Item in room : A potion (type 'take' to pick it up)"<< endl;
        }else{
            cout <<  "You search the room and it doesn't have any items"<< endl;
        }
    } else {
        cout << "Type \"restart\" or \"exit\"." << endl;
    }
}
