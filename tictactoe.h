/*********************************************
* Assignment 2
* 
* Programmer: Dilara Liyanage
* ID: IT23285606
* Batch:CS/E Group 1
* Date completed: November 17, 2023
*
* Create a tictactoe game (header file)
**********************************************/


#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "tictactoe_state.txt"
#define player_1 'X'
#define player_2 'O'

void initializeBoard(int N, char ***board);
void displayBoard(int N, char **board);
int makeMove(int N, char **board, char player, FILE *file);
int checkWin(int N, char **board);
int checkDraw(int N, char **board);


#endif