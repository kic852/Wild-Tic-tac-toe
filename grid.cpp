// Name: Hon Ki Ching

#include "grid.h"
#include <iostream>
using namespace std;

/* Prints grid to the screen. Do NOT modify! */
void printGrid(int grid) {
   char p1, p2, p3, p4, p5, p6, p7, p8, p9;   // Positions 1-9
   int d;

   d = grid / 100000000;
   p1 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 10000000 % 10;
   p2 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 1000000 % 10;
   p3 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 100000 % 10;
   p4 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 10000 % 10;
   p5 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 1000 % 10;
   p6 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 100 % 10;
   p7 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid / 10 % 10;
   p8 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));
   d = grid % 10;
   p9 = (d == 1 ? 'X' : (d == 2 ? 'O' : ' '));

   cout << " " << p1 << " | " << p2 << " | " << p3 << endl;
   cout << "---+---+---" << endl;
   cout << " " << p4 << " | " << p5 << " | " << p6 << endl;
   cout << "---+---+---" << endl;
   cout << " " << p7 << " | " << p8 << " | " << p9 << endl;
}

/* Returns whether position pos of grid is already filled with a mark */
bool isFilled(int grid, int pos) {
    // TODO; add a return statement in order to compile
   
   //find the pos th digit
   for (int i=0; i < 9-pos;i++){
      grid/=10;
   }
   grid%=10;

   //return statement return 1 if it's empty, while 0 if it's filled
   if (grid!=0){
      return 1;
   }
   else {
      return 0;
   }
}

/* Models the game move from a player putting a mark in position pos of grid.
   Returns true if a horizontal/vertical/diagonal line of three same marks is
   formed. */
bool updateGrid(int &grid, int pos, char mark) {
    // TODO; add a return statement in order to compile

   //update the grid digit
   int x = (mark == 'X' ? 1 : 2 );

   for (int i=0; i<9-pos;i++){
      x *=10;
   }
   grid += x;

   int p1, p2, p3, p4, p5, p6, p7, p8, p9; 
   p1 = grid / 100000000;
   p2 = grid / 10000000 % 10;
   p3 = grid / 1000000 % 10;
   p4 = grid / 100000 % 10;
   p5 = grid / 10000 % 10;
   p6 = grid / 1000 % 10;
   p7 = grid / 100 % 10;
   p8 = grid / 10 % 10;
   p9 = grid % 10;

   //check if there fromed same horizontally
   if (p1 !=0 && p1 == p2 && p1 == p3){
      return 1;
   }
   
   else if (p4 !=0 && p4 == p5 && p4 == p6 ){
      return 1;
   }
   else if (p7 !=0 && p7 == p8 && p7 == p9 ){
      return 1;
   }

   //check if there formed vertically
   else if (p1 !=0 && p1 == p4 && p1 == p7 ){
      return 1;
   }
   else if (p2 !=0 && p2 == p5 && p2 == p8 ){
      return 1;
   }
   else if (p3 !=0 && p3 == p6 && p3 == p9 ){
      return 1;
   }

   //check if there formed dia
   else if (p1 !=0 && p1 == p5 && p1 == p9 ){
      return 1;
   }
   else if (p3 !=0 && p3 == p5 && p3 == p7 ){
      return 1;
   }
   
   else{
      return 0;
   }
}

/* You may write a main() in this file for debugging purpose, but it must be
   removed or commented in your submitted version. */
