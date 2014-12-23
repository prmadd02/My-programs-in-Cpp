// Tic-Tac-Toe Game
// Author: Paul Maddox 
// Date: 3/20/14

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;
using std::string;

class Board {
      private:
             int grid[3][3];
             int first;
             int winner;
              
      public:
             // Builder & Destroyer
             Board();
             
             
             //Get and Set
             void setCell(int x, int y, int value);
             int getWinner();
             int setWinner(int value);
             
             void makeMove();
             void playerMove();
             void computerMove();
             
             void printGrid();
             bool isValid(int x, int y);
             void error(int x, int y);
             void checkWinner();
             bool isDraw();
             void goesFirst();
             };
      
      // Build       
      Board::Board() {
      setWinner(0);
      for (int i = 0; i < 9; i++) { //intializes the board with all values being 0
                setCell((i / 3), (i % 3), 0);
                }
      }

void Board::goesFirst() {
     srand(time(NULL));
     first = (rand() % 2);
     if (first == 0) {
               cout << "You go first.\n" << endl;
     } else {
               cout << "Computer goes first.\n" << endl;
     }
     system("pause");
}

int Board::getWinner() {
    return winner;
}

int Board::setWinner(int value) {
    winner = value;
}

void Board::setCell(int x, int y, int value) {
            grid[x][y] = value;
            }

bool Board::isValid(int x, int y) {
     return (((x > -1) && (x < 3)) && ((y > -1) && (y < 3)) && !(grid[x][y]));
     }
     
void Board::error(int x, int y) {
     if (((x < -1) || (x > 3)) || ((y < -1) || (y > 3))) {
             cout << "Please enter integers between 0 and 2 for row/column." << endl;
     } else if (grid[x][y]) {
             cout << "That space is already occupied." << endl;
             }
     }
     
string dispChar(int num) {
       string c = "";
       if (num) {
                if (num == 3) {
                        c = "X";
                        } else {
                        c = "O";
                        }
       } else {
         c = " ";
         }
       return c;
       }
     
void Board::printGrid() {
    cout << "     0 | 1 | 2 " << endl;
    cout << "  ------------" << endl;
    cout << "   |   |   |   " << endl;
    cout << "0  | " << dispChar(grid[0][0]).c_str() << " | " << dispChar(grid[1][0]).c_str() << " | " << dispChar(grid[2][0]).c_str() << " " << endl;
    cout << "   |   |   |   " << endl;
    cout << "  ------------" << endl;
    cout << "   |   |   |   " << endl;
    cout << "1  | " << dispChar(grid[0][1]).c_str() << " | " << dispChar(grid[1][1]).c_str() << " | " << dispChar(grid[2][1]).c_str() << " " << endl;
    cout << "   |   |   |   " << endl;
    cout << "  ------------" << endl;
    cout << "   |   |   |   " << endl;
    cout << "2  | " << dispChar(grid[0][2]).c_str() << " | " << dispChar(grid[1][2]).c_str() << " | " << dispChar(grid[2][2]).c_str() << " " << endl;
    cout << "   |   |   |   " << endl;
    cout << endl << endl;
}

void Board::checkWinner() {
    for(int j = 0; j < 3; j++) {
    	if (grid[0][j] + grid[1][j] + grid[2][j] == 9) {
    		winner = 3;
    	} else if (grid[0][j] + grid[1][j] + grid[2][j] == 12) {
    		winner = 4;
    	}
    }
    
    for(int k = 0; k < 3; k++) {
    	if (grid[k][0] + grid[k][1] + grid[k][2] == 9) {
    		winner = 3;
    	} else if (grid[k][0] + grid[k][1] + grid[k][2] == 12) {
    		winner = 4;
    	}
    }
    
    if (grid[0][0] + grid[1][1] + grid[2][2] == 9) {
    	winner = 3;
    } else if (grid[0][0] + grid[1][1] + grid[2][2] == 12) {
    	winner = 4;
    }
    
    if (grid[0][2] + grid[1][1] + grid[2][0] == 9) {
    	winner = 3;
    } else if (grid[0][2] + grid[1][1] + grid[2][0] == 12) {
    	winner = 4;
    }
}

bool Board::isDraw() {
     bool draw = true;
     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             if (grid[i][j] == 0) {
                     draw = false;
                     }
                     }
         }
     return draw;
                }

void Board::makeMove() {
     bool draw;
           if (first == 0) {
                     while (!(getWinner() || draw)) {
                           playerMove();
                           system("cls");
                           printGrid();
                           checkWinner();
                           draw = isDraw();
                           if (!(isDraw() || getWinner())) {
                           computerMove();
                           system("cls");
                           printGrid();
                           checkWinner();
                           draw = isDraw();
                           }
                           }
           } else {
               while (!(getWinner() || draw)) {
                   computerMove();
                   system("cls");
                   printGrid();
                   checkWinner();
                   draw = isDraw();
                   if (!(isDraw() || getWinner())) {
                   playerMove();
                   system("cls");
                   printGrid();
                   checkWinner();
                   draw = isDraw();
                   }
           }
     }
}

void Board::computerMove() {
     int row, col;
     row = rand()%3;
     col = rand()%3;
     if (isValid(col, row)) {
        setCell(col, row, 4);
     } else {
            computerMove();
     }
     }

     
void Board::playerMove() {
     int row, col;
     cout << "What Column? (0, 1, 2)";
     cin >> col;
     cout << "What Row? (0, 1, 2)";
     cin >> row;
     if (isValid(col, row)) {
        setCell(col, row, 3);
     } else {
           error(col,row);
           printGrid();
           playerMove();
     }
     }

    main() {
    	int iresponse;
            Board board1;
            cout << "Welcome to Tic-Tac-Toe!" << endl;
            board1.goesFirst();
            board1.printGrid();
            board1.makeMove();
            if (board1.getWinner()) {
               cout << "The winner is player " << dispChar(board1.getWinner()).c_str() << endl;
            } else if (board1.isDraw()) {
               cout << "The game has ended in a draw. CATs won the Game" << endl;
            }       
            cout << "Would like to play again?\n";
            cout << "1 for Yes\n";
            cout << "2 for No\n";
            cin >> iresponse;
            if (iresponse < 2){
            	return main();
            } else {
            return 0;
			}
	}
