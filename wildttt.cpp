// Name: Hon Ki Ching

#include "grid.h"
#include <iostream>
using namespace std;


/* Implements the game flow */
int main() {
    // TODO
    int GameStatus =0; //0: still playing, 1: player1 win, 2: player2 win, 3: draw
    int grid = 000000000; // intialise the grid
    int player = 1,move =0,pos;
    char mark;
    while (GameStatus ==0){
        
        printGrid(grid);

        
        bool InputCon = (mark == 'X' || mark == 'O' )&&(pos>=1 && pos <=9)&& !isFilled(grid,pos);//condition expression
        
        //checl if the input is valid
        do
        {
            cout << "Player " << player<<"'s move: ";
            cin >> mark >> pos;
            InputCon = (mark == 'X' || mark == 'O' )&&(pos>=1 && pos <=9)&& !isFilled(grid,pos);//condition expression
            if (!InputCon){
                cout << "Invalid! Try again." << endl;
            }
            } while (!InputCon);
        move+=1;
        if(updateGrid(grid,pos,mark)){
            GameStatus = player;
        }
        else if(move == 9){
            GameStatus = 3;
        }
        player = (player == 1 ? 2 : 1);
        

    }
    printGrid(grid);
    if (GameStatus == 3){
        cout << "Draw game!"<<endl;
    }
    else{
        cout << "player " << GameStatus <<" wins!";
    }
    return 0;
}
