//  Created by Ibraheem Nadeem on 11/30/14.
//  Tic Tac Toe Game


// prototypes:

void ResetBoard (char board [3][3]);
void DisplayBoard (char board[3][3]);
int selectLocation (char turn, char board[3][3], int *location);
void setTurn (char board [3][3], int *, char turn);
int checkForWin (char board [3][3]);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int location, i, win=0;
    int locationSelect;
    char board [3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    char turn = 'X';  // Initialize the first player to Player X
    char playAgain;   // Will let the user play again if they enter Y or y
    
    do {
        
        ResetBoard(board);   // New Board from 1-9
        do {
            
            for (i=0; i<9; i++)
            {
                DisplayBoard (board);   // Displays The Board
                locationSelect = selectLocation(turn, board, &location);  // Asks user for location
                setTurn (board,&location,turn);  // Puts either X or O onto board
                win = checkForWin (board);  // Checks if Win ==1 or 0
                
                if (win ==1)  // if win ==1, then then the player wins
                {
                    printf("\n\n*********************************");
                    printf("\n\nPlayer %c Won!", turn);
                    DisplayBoard(board);
                    
                    printf("\n*********************************");
                    
                    break; // Breaks the loop if the player wins
                }
                
                if (turn == 'X')      // This statement switches the players once it loops again
                    turn = 'O';
                else
                    turn = 'X';
                
            }
            
            if (win==0 && i==9) // Will determine tie game
            {
                printf("\nIt was a tie game!\n");
                DisplayBoard(board);
                
                break; // Breaks loop if it's a tie game
            }
        } while (win==0);
        
        
        printf("\n\nWould you like to play again?: (Y or N)");
        scanf("\n%c", &playAgain);
        
    } while (playAgain == 'Y' || playAgain == 'y'); // Will keep looping if player enters Y or y
    
    printf("\n\nThank you for playing!");
    return 0;
}

// *****************************************************************
// Function that will display the board

void DisplayBoard (char board[3][3])

{
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    
}

// *****************************************************************
// Function that will reset the board values
void ResetBoard (char board [3][3])

{
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
}

// *****************************************************************

int selectLocation (char turn, char board[3][3], int *location)
{
    int valid=0;

    // Do while loop that has a do while loop and a switch statement within.
    // First will ask user to enter location and it will keep asking if location <1 or location>9.
    /* It will then go to the switch statement and determine if the location of the board is == X or O.
    If it is, it will then set valid =-1 and will loop to the top again and ask them to enter another location.
    */
    
    do {
       
        do {
            
        printf("\n\nPlayer %c Please Enter a location (1-9): ", turn);
        scanf("%d", &*location);
        
        if (*location<1 || *location>9) {
            
            printf("\nInvalid Choice");
            printf("\n\nPlayer %c Please Enter a location (1-9): ", turn);
            scanf("%d", &*location);
        }
            
        } while (*location<1 || *location>9);
        
        switch (*location) {
            case 1:
                if (board[0][0] == 'X' || board[0][0] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 2:
                if (board[0][1] == 'X' || board[0][1] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 3:
                if (board[0][2] == 'X' || board[0][2] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 4:
                if (board[1][0] == 'X' || board[1][0] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 5:
                if (board[1][1] == 'X' || board[1][1] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 6:
                if (board[1][2] == 'X' || board[1][2] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 7:
                if (board[2][0] == 'X' || board[2][0] == 'O')
                {
                    printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 8:
                if (board[2][1] == 'X' || board[2][1] == 'O')
                { printf("\nInvalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            case 9:
                if (board[2][2] == 'X' || board[2][2] == 'O')
                {
                    printf("\n Invalid Choice, please enter another location");
                    valid=-1;
                }
                else
                    valid=1;
                break;
            default:
                printf("\n Please enter a location between 1 and 9");
                break;
        }
        
    } while (valid==-1);

    return *location;
}

// *****************************************************************

// Will change the board and make it either X or O depending on the location selected by the user

void setTurn (char board [3][3], int *location, char turn)


{
    
    switch (*location) {
        case 1:
            board[0][0] = turn;
            break;
        case 2:
            board[0][1] = turn;
            break;
        case 3:
            board[0][2] = turn;
            break;
        case 4:
            board[1][0] = turn;
            break;
        case 5:
            board[1][1] = turn;
            break;
        case 6:
            board[1][2] = turn;
            break;
        case 7:
            board[2][0] = turn;
            break;
        case 8:
            board[2][1] = turn;
            break;
        case 9:
            board[2][2] = turn;
        default:
            break;
    }
    
}

// *****************************************************************
// Will check All the 8 possible combinations of winning will return either 1 or 0
int checkForWin (char board [3][3])

{
    
    if ((board [0][0] == board [1][1] && board [0][0] == board [2][2]) || (board [0][2] == board [1][1] && board [0][2] == board [2][0]) || (board [0][0] == board [0][1] && board [0][0] == board [0][2]) || (board [1][0] == board [1][1] && board [1][0] == board [1][2]) || (board [2][0] == board [2][1] && board [2][0] == board [2][2]) || (board [0][0] == board [1][0] && board [0][0] == board [2][0]) || (board [0][1] == board [1][1] && board [0][1] == board [2][1]) || (board [0][2] == board [1][2] && board [0][2] == board [2][2]))
        
        return 1;
    
    else
        return 0;
    
}

// *****************************************************************

