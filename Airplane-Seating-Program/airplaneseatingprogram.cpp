#include <iostream>

using namespace std;

int main(){
    
   const int ROWS = 13;
   const int COLS = 6;
   
   char seats [ROWS][COLS];
   char ticketType, smoking, colName, choice;
   int pRow, pCol;
   
   cout << "\n\n\tProgram that organizes Airplane Seating Arrangement.\n\n";

    for ( int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j]; '*';
    
    do{
        cout << "\n\t\tA\tB\tC\tD\tE\tF";
        for (int i = 0; i < ROWS; i++){
            
            cout << "\n\tRow " << (i+1);
            
            for (int j = 0; j < COLS; j++)
                cout << "\t" << seats[i][j];
        }
    
    cout << "\n\n\tEnter Ticket type (F/E): ";
    cin >> ticketType; 
    
    if (ticketType == 'e' || ticketType == 'E'){
        
        cout << "\n\tEnter smoking section (Y/N): ";
        cin >> smoking;
    }
    else
        smoking = 'n';
    
    cout << "\n\tEnter preferred Seat Row Number: ";
    cin >> pRow;
    
    if ((tolower(ticketType) == 'f') && (pRow > 2)){
        
        cout << "\n\n\tNot a valid first class seat.";
        continue;
    }
    
    if ((tolower(smoking == 'y')) && (pRow <= 7)){
        
        cout << "\n\n\tNot a valid smoking section.";
        continue;
    }
    
    if ((tolower(smoking != 'y')) && (pRow > 7)){
        
        cout << "\n\n\tNot a valid non-smoking section.";
        continue;
    }
    
    if ((tolower(ticketType == 'e')) && (pRow <= 2)){
        
        cout << "\n\n\tNot a valid economy class seat.";
        continue;
        
    }
    
    cout << "\tEnter preferred seat col name: ";
    cin >> colName;
        
    pCol = static_cast<int> (tolower(colName) - 97);
    
    if (pCol < 0 || pCol > COLS){
        
        cout << "\n\n\tInvalid column name.";
        continue;
    }
    
    if (seats[pRow][pCol] == 'X')
        
        cout << "\n\tAlready reserved. No vacancy.";
    
    else{
        seats[pRow - 1][pCol] = 'X';
        cout << "\n\tSeat was reserved for you.";
        
    }
    
    cout << "\n\tOne more ticket to reserve (Y/N): ";
    cin >> choice;
    
    
    }
    
    while (tolower(choice) !='n');
    
    return 0;
}
