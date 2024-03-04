/*********************************************
* Assignment 2
* 
* Programmer: Dilara Liyanage
* ID: IT23285606
* Batch:CS/E Group 1
* Date completed: November 17, 2023
*
* Create a tictactoe game (main)
**********************************************/


#include "tictactoe.h"

int main() {
        int N;

        do {
                printf(" Enter board size ( 3 < SIZE < 10 ): ");
                scanf("%d", &N);
                //Prompt user to enter the board size

                if ( N <= 3 || N >= 10 ) {
                        printf("Invalid board size. Please enter a valid size. ( 3 < SIZE < 10 )\n");
                }
        } while ( N <= 3 || N >= 10);

        char **board;
        FILE *file;

        file = fopen(FILENAME, "w");
        //open the file for writing

        if ( file == NULL) {
                printf("Error openning file. Exiting...\n");
                return 1;
        }

        initializeBoard(N, &board);

        //Game Loop
        while (1) {
                //For player 1 move (X)
                displayBoard(N, board);
                if ( makeMove(N, board, player_1, file)) {
                        if ( checkWin(N, board)) {
                                printf ("PLAYER X WINS!\n");
                                break;
                        }
                        if (checkDraw(N, board)) {
                                printf("GAME OVER ~ The game is drawn!\n");
                                break;
                        }
                }

                //For player 2 move (O)
                displayBoard(N, board);
                if( makeMove(N, board, player_2, file)) {
                        if ( checkWin(N, board)) {
                                printf ("PLAYER O WINS!\n");
                                break;
                        }
                        if (checkDraw(N, board)) {
                                printf("GAME OVER ~ The game is drawn!\n");
                                break;
                        }
                }
        }

        fclose(file);
        //close the file

        //Free the allocated memory
        for (int i = 0; i < N; i++) {
                free(board[i]);
        }
        free(board);

    return 0;
}