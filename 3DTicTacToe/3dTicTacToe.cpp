// 3D Tic-Tac-Toe Game
// Author: Paul Maddox
// Date: 3/27/14
// Section: 2

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;
using std::string;

class Game {
      protected:
              int winner;  
      public:
             void welcome();
      };

void Game::welcome() {
     cout << "Welcome to 3D tic-tac-toe!\n" << endl;
     cout << "The goal of this game is to make as many winning moves as possible.\n" << endl;
     cout << "The rules are the same as normal tic-tac-toe except the games won't end till the board is full.\n" << endl;
}

class Board: public Game {
      private:
             int grid[3][3][3];
             int first;
             int points[1];
             int computer;
             int player;
              
      public:
             // Constructor and Deconstructor:
             Board();
             //~Board();
             
             // getters and setters:
             void setCell(int x, int y, int z, int value);
             void getWinner();
             int setWinner(int value);
             
             void makeMove();
             void playerMove();
             void computerMove();
             
             void printGrid();
             bool isValid(int x, int y, int z);
             void error(int x, int y, int z);
             void checkWinner();
             bool isOver();
             void goesFirst();
             };
      
      // Constructor       
      Board::Board() {
      setWinner(0);
      for (int i = 0; i < 9; i++) { //intializes the board with all values being 0
                setCell((i / 3), (i % 3), 0, 0);
                setCell((i / 3), (i % 3), 1, 0);
                setCell((i / 3), (i % 3), 2, 0);
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

void Board::getWinner() {
    cout << "Final Score:" << endl;
    cout << "Player: " << points[0] << endl;
    cout << "Computer: " << points[1] << endl;
    if (points[0] > points[1]) {
                  cout << "Player wins!" << endl;
    } else if (points[1] > points[0]) {
           cout << "Computer wins!" << endl;
    } else if (points[0] == points[1]) {
           cout << "Game ended in a tie." << endl;
           }
    
}

int Board::setWinner(int value) {
    Game::winner = value;
}

void Board::setCell(int x, int y, int z, int value) {
            grid[x][y][z] = value;
            }

bool Board::isValid(int x, int y, int z) {
     return (((x > -1) && (x < 3)) && ((y > -1) && (y < 3) && ((z > -1) && (z < 3))) && !(grid[x][y][z]));
     }
     
void Board::error(int x, int y, int z) {
     if (((x < -1) || (x > 3)) || ((y < -1) || (y > 3)) || ((z < -1) && (z > 3))) {
             cout << "Please enter integers between 0 and 2 for row/column/board." << endl;
     } else if (grid[x][y][z]) {
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
    cout << " Board 0: " << endl;
    cout << "   0 | 1 | 2 " << endl;
    cout << " ------------" << endl;
    cout << " |   |   |   " << endl;
    cout << "0| " << dispChar(grid[0][0][0]).c_str() << " | " << dispChar(grid[1][0][0]).c_str() << " | " << dispChar(grid[2][0][0]).c_str() << " " << endl;
    cout << " |   |   |   " << endl;
    cout << " ------------" << endl;
    cout << " |   |   |   " << endl;
    cout << "1| " << dispChar(grid[0][1][0]).c_str() << " | " << dispChar(grid[1][1][0]).c_str() << " | " << dispChar(grid[2][1][0]).c_str() << " " << endl;
    cout << " |   |   |   " << endl;
    cout << " ------------" << endl;
    cout << " |   |   |   " << endl;
    cout << "2| " << dispChar(grid[0][2][0]).c_str() << " | " << dispChar(grid[1][2][0]).c_str() << " | " << dispChar(grid[2][2][0]).c_str() << " " << endl;
    cout << " |   |   |   " << endl;
    cout << endl;
    
    cout << "\t Board 1: " << endl;
    cout << "\t   0 | 1 | 2 " << endl;
    cout << "\t ------------" << endl;
    cout << "\t |   |   |   " << endl;
    cout << "\t0| " << dispChar(grid[0][0][1]).c_str() << " | " << dispChar(grid[1][0][1]).c_str() << " | " << dispChar(grid[2][0][1]).c_str() << " " << endl;
    cout << "\t |   |   |   " << endl;
    cout << "\t ------------" << endl;
    cout << "\t |   |   |   " << endl;
    cout << "\t1| " << dispChar(grid[0][1][1]).c_str() << " | " << dispChar(grid[1][1][1]).c_str() << " | " << dispChar(grid[2][1][1]).c_str() << " " << endl;
    cout << "\t |   |   |   " << endl;
    cout << "\t ------------" << endl;
    cout << "\t |   |   |   " << endl;
    cout << "\t2| " << dispChar(grid[0][2][1]).c_str() << " | " << dispChar(grid[1][2][1]).c_str() << " | " << dispChar(grid[2][2][1]).c_str() << " " << endl;
    cout << "\t |   |   |   " << endl;
    cout << endl;
    
    cout << "\t\t Board 2: " << endl;
    cout << "\t\t   0 | 1 | 2 " << endl;
    cout << "\t\t ------------" << endl;
    cout << "\t\t |   |   |   " << endl;
    cout << "\t\t0| " << dispChar(grid[0][0][2]).c_str() << " | " << dispChar(grid[1][0][2]).c_str() << " | " << dispChar(grid[2][0][2]).c_str() << " " << endl;
    cout << "\t\t |   |   |   " << endl;
    cout << "\t\t ------------" << endl;
    cout << "\t\t |   |   |   " << endl;
    cout << "\t\t1| " << dispChar(grid[0][1][2]).c_str() << " | " << dispChar(grid[1][1][2]).c_str() << " | " << dispChar(grid[2][1][2]).c_str() << " " << endl;
    cout << "\t\t |   |   |   " << endl;
    cout << "\t\t ------------" << endl;
    cout << "\t\t |   |   |   " << endl;
    cout << "\t\t2| " << dispChar(grid[0][2][2]).c_str() << " | " << dispChar(grid[1][2][2]).c_str() << " | " << dispChar(grid[2][2][2]).c_str() << " " << endl;
    cout << "\t\t |   |   |   " << endl;
    cout << endl << endl;
}

void Board::checkWinner() {
     points[0] = 0;
     points[1] = 1;
     computer = 0;
     player = 0;
    for(int i = 0; i < 3; i++) {
        
        for(int j = 0; j < 3; j++) {
        	if (grid[0][j][i] + grid[1][j][i] + grid[2][j][i] == 9) {
        		player += 1;
        	} else if (grid[0][j][i] + grid[1][j][i] + grid[2][j][i] == 12) {
        		computer += 1;
        	}
        }
    
        for(int k = 0; k < 3; k++) {
        	if (grid[k][0][i] + grid[k][1][i] + grid[k][2][i] == 9) {
        		player += 1;
        	} else if (grid[k][0][i] + grid[k][1][i] + grid[k][2][i] == 12) {
        		computer += 1;
        	}
        }
    
        if (grid[0][0][i] + grid[1][1][i] + grid[2][2][i] == 9) {
        	player += 1;
        } else if (grid[0][0][i] + grid[1][1][i] + grid[2][2][i] == 12) {
        	computer += 1;
        }
    
        if (grid[0][2][i] + grid[1][1][i] + grid[2][0][i] == 9) {
        	player += 1;
        } else if (grid[0][2][i] + grid[1][1][i] + grid[2][0][i] == 12) {
        	computer += 1;
        }
        
        if (grid[i][0][0] + grid[i][1][1] + grid[i][2][2] == 9){ 
           player += 1;
           } else if (grid[i][0][0] + grid[i][1][1] + grid[i][2][2] == 12){
           computer += 1;
        }
        
        if (grid[i][2][0] + grid[i][1][1] + grid[i][0][2] == 9){ 
           player += 1;
           } else if (grid[i][2][0] + grid[i][1][1] + grid[i][0][2] == 12){
           computer += 1;
        }
    
        if (grid[0][i][0] + grid[1][i][1] + grid[2][i][2] == 9){ 
           player += 1;
           } else if (grid[0][i][0] + grid[1][i][1] + grid[2][i][2] == 12){
           computer += 1;
        }
        
        if (grid[2][i][0] + grid[1][i][1] + grid[0][i][2] == 9){ 
           player += 1;
           } else if (grid[2][i][0] + grid[1][i][1] + grid[0][i][2] == 12){
           computer += 1;
        }
    }
    
    for(int l = 0; l < 9; l++) {
          if (grid[l/3][l%3][0] + grid[l/3][l%3][1] + grid[l/3][l%3][2] == 9) {
              player += 1;
          } else if (grid[l/3][l%3][0] + grid[l/3][l%3][1] + grid[l/3][l%3][2] == 12) {
               computer += 1;
          }
    }
        
        // check side diagonals.
    if (grid[0][0][0] + grid[1][1][1] + grid[2][2][2] == 9) {
       player += 1;
    } else if (grid[0][0][0] + grid[1][1][1] + grid[2][2][2] == 12) {
       computer += 1;
    }
    
    if (grid[2][2][0] + grid[1][1][1] + grid[0][0][2] == 9) {
       player += 1;
    } else if (grid[2][2][0] + grid[1][1][1] + grid[0][0][2] == 12) {
       computer += 1;
    }   
    
    if (grid[2][0][0] + grid[1][1][1] + grid[0][2][2] == 9) {
       player += 1;
    } else if (grid[2][0][0] + grid[1][1][1] + grid[0][2][2] == 12) {
       computer += 1;
    }   
    
    if (grid[0][2][0] + grid[1][1][1] + grid[2][0][2] == 9) {
       player += 1;
    } else if (grid[0][2][0] + grid[1][1][1] + grid[2][0][2] == 12) {
       computer += 1;
    }   
    
    points[0] = player;
    points[1] = computer;

}

bool Board::isOver() {
     bool over = true;
     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
             for (int k = 0; k < 3; k++) {
                 if (grid[i][j][k] == 0) {
                     over = false;
                     }
                     }
                     }
         }
     return over;
                }
                


void Board::makeMove() {
     bool draw = false;
           if (first == 0) {
                     while (!draw) {
                           checkWinner();
                           cout << "Player: " << points[0] << endl;
                           cout << "CPU: " << points[1] << endl;
                           playerMove();
                           printGrid();
                           draw = isOver();
                           if (!isOver()) {
                           checkWinner();
                           cout << "Player: " << points[0] << endl;
                           cout << "CPU: " << points[1] << endl;
                           computerMove();
                           printGrid();
                           draw = isOver();
                           checkWinner();
                           cout << "Player: " << points[0] << endl;
                           cout << "CPU: " << points[1] << endl;
                           }
                           }
           } else {
               while (!draw) {
                     checkWinner();
                     cout << "Player: " << points[0] << endl;
                     cout << "CPU: " << points[1] << endl;
                   computerMove();
                   printGrid();
                   draw = isOver();
                   if (!isOver()) {
                   checkWinner();
                   cout << "Player: " << points[0] << endl;
                   cout << "CPU: " << points[1] << endl;
                   playerMove();
                   printGrid();
                   draw = isOver();
                   checkWinner();
                   cout << "Player: " << points[0] << endl;
                   cout << "CPU: " << points[1] << endl;
                   }
           }
     }
}

void Board::computerMove() {
     int row, col, brd;
     row = rand()%3;
     col = rand()%3;
     brd = rand()%3;
     if (isValid(col, row, brd)) {
        setCell(col, row, brd, 4);
     } else {
            computerMove();
     }
     }

     
void Board::playerMove() {
     int row, col, brd;
     cout << "\nWhat column? (0, 1, 2) ";
     cin >> col;
     cout << "\nWhat row? (0, 1, 2) ";
     cin >> row;
     cout << "\nWhat board? (0, 1, 2) ";
     cin >> brd;
     if (isValid(col, row, brd)) {
        setCell(col, row, brd, 3);
     } else {
           error(col,row, brd);
           printGrid();
           playerMove();
     }
     }

    main() {
    	int iresponse;
            Board board1;
            board1.welcome();
            board1.goesFirst();
            board1.printGrid();
            board1.makeMove();
            board1.getWinner();
            
            cout << "Would like to play again?\n";
            cout << "1 for Yes\n";
            cout << "2 for No\n";
            cin >> iresponse;
            if (iresponse < 2){
            	return main();
            } else {
            cout << "Good Bye!";	
            return 0;
			}
    }
