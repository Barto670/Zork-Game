#ifndef NPC_H
#define NPC_H

#endif // NPC_H

#include <iostream>
#include<string>

using namespace std;

class NPC {
   string text;
   public:
      friend void printWidth( NPC adventurer );
      void setText( string txt );
      string getText();
};

void NPC::setText( string txt ) {
   text = txt;
}

string NPC::getText() {
   return text;
}

void printText( NPC adventurer ) {
   cout << "NPC : " << adventurer.getText() <<endl;
}




