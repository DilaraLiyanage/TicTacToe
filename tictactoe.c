/*********************************************
* Assignment 2
* 
* Programmer: Dilara Liyanage
* ID: IT23285606
* Batch:CS/E Group 1
* Date completed: November 17, 2023
*
* Create a tictactoe game (functions)
**********************************************/


#include "tictactoe.h"

void initializeBoard(int N, char ***board) {
        *board = ( char **)malloc(N * sizeof(char *));
        for(int i = 0; i < N; i++) {
                (*board)[i] = (char *)malloc(N * sizeof(char));
                for(int j = 0; j < N; j++) {
                        (*board)[i][j] = ' ';
                }
        }
}


void displayBoard(int N, char **board) {
        //Display column numbers
        printf("  ");
        for (int i = 1; i <= N; i++) {
                printf("%d ", i);
        }
        printf("\n");

        //Display the board
        for (int i = 0; i < N; i++) {
                printf("%d|", i+1);
                for (int j = 0; j < N; j++) {
                        printf("%c|", board[i][j]);
                }
                printf("\n");
        }
}


int makeMove(int N, char **board, char player, FILE *file) {
        int row, col;

        do {
                printf("Move (%c) (row column): ", player);
                //prompt the player to enter their move (row column)
                scanf("%d %d", &row, &col);

                row--;
                col--;
                //Adjust row and col to 0-based index

                if (row < 0 || row >= N || col < 0 || col>= N || board[row][col] != ' '){
                        printf("Invalid move. Try again.\n");
                }
                //check if the move is valid r<N and c<N and not already occupied
                else{
                        board[row][col] = player;
                        //update the board with players symbol

                        fprintf(file, "Move (%c) : %d %d\n", player, row+1, col+1);
                        return 1;
                        //save the state to a file
                }
        } while(1);
        //to loop until a player enters a valid move
        //return 1 if move is valid

        return 0;
        //to satisfy function return type
}


int checkWin(int N, char **board) {
        //check rows
        for(int i = 0; i < N; i++) {
                int  rWin = 1;
                for(int j = 0; j < N-1; j++) {
                        if (board[i][j] != board[i][j+1] || board[i][j] == ' ') {
                                rWin = 0;
                                break;
                        }
                }
                if (rWin == 1) {
                        return 1;
                }
        }


        //check columns
        for(int j =0; j < N; j++) {
                int cWin = 1;
                for(int i = 0; i < N-1; i++) {
                        if (board[i][j] != board[i+1][j] || board[i][j] == ' ') {
                                cWin = 0;
                                break;
                        }
                }
                if (cWin == 1){
                       return 1;
                }
        }

        //check diagonals
        int d1Win = 1; //from [0][0] to [N-1][N-1]
        int d2Win = 1; //from [0][N-1] to [N-1][0]
        
        for (int i = 0; i < N-1; i++) {
                if (board[i][i] != board[i+1][i+1] || board[i][i] == ' ') {
                        d1Win = 0;
                        break;
                }
        }
        for (int i=0; i < N-1; i++) {
                if (board[i][N-1-i] != board[i+1][N-i-2] || board[i][N-1-i] == ' ' ){
                        d2Win = 0;
                        break;
                }
        }

        if (d1Win == 1 || d2Win == 1){
                        return 1;
        }

        return 0;
        //if player wins return 1, else 0
}


int checkDraw(int N, char **board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == ' ') {
                // If there is an empty space, the game is not a draw
                return 0;
            }
        }
    }
    // If there is no empty spaces, the game is a draw
    return 1;
}