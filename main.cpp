//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Leron Julian on 10/7/16.
//  Copyright © 2016 Leron Julian. All rights reserved.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "PlayerPiece.h"
#include "CPU piece.h"
#include "Winner.h"
using namespace std;

Player_piece playerPiece;
CPU_piece cpuPiece;
Winner winnerPiece;

struct tic_tac_toe {
    char board[3][3];
};

char player1 = playerPiece.getPlayerPiece();
char cpu = cpuPiece.getCpuPiece();

void initalize_board (char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}


void print_board(char board[3][3]) {
    cout << "- - - - - - - - -" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}



char check_win(char board[3][3]) {
    if (board[0][0] != ' ' && ((board[0][0] == board[0][1] && board[0][0] == board[0][2]) ||
                               (board[0][0] == board[1][0] && board[0][0] == board[2][0]) ||
                               (board[0][0] == board[1][1] && board[0][0] == board[2][2])))
        return board[0][0];
    
    if (board[1][1] != ' ' && ((board[1][1] == board[1][0] && board[1][1] == board[1][2]) ||
                               (board[1][1] == board[0][1] && board[1][1] == board[2][1]) ||
                               (board[1][1] == board[2][0] && board[1][1] == board[0][2])))
        return board[1][1];
    
    if (board[2][2] != ' ' && ((board[2][2] == board[0][2] && board[2][2] == board[1][2]) ||
                               (board[2][2] == board[2][0] && board[2][2] == board[2][1])))
        return board[2][2];
    
    return 0;
}


int negamax(char board[3][3], char player1, char player2);

int pick_best_move(char board[3][3], char player1, char player2) {
    
    int best_move_score = -9999;
    int best_move_row = -9999;
    int best_move_col = -9999;
    int score_for_this_move = 0;
    
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == ' ') {
                board[r][c] = player1;
                score_for_this_move = -(negamax(board, player2, player1));
                board[r][c] = ' ';
                if (score_for_this_move >= best_move_score) {
                    best_move_score = score_for_this_move;
                    best_move_row = r;
                    best_move_col = c;
                }
            }
        }
    }
    return (10 * best_move_row + best_move_col);
}



int negamax(char board[3][3], char player1, char player2) {
    int best_move_score = -9999;
    
    int score_for_this_move = 0;
    if (check_win(board) == player1)
        return 1000;
    
    else if (check_win(board) == player2)
        return -1000;
    
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == ' ') {
                board[r][c] = player1;
                
                score_for_this_move = -(negamax(board, player2, player1));
                board[r][c] = ' ';
                if (score_for_this_move >= best_move_score) {
                    
                    best_move_score = score_for_this_move;
                }
            }
        }
    }
    
    if (best_move_score == -9999 || best_move_score == 0)
        return 0;
    else if (best_move_score < 0)
        return best_move_score + 1;
    else if (best_move_score > 0)
        return best_move_score - 1;
    return NULL;
}





void player_placement(char board[3][3], char player) {
    while (1) {
        string string_row, string_col;
        int row = 0, col = 0;
        while (1) {
            cout << "Enter the row (Number Only): ";
            cin >> string_row;
            
            //atoi converts a string to an integer. c_str passes the characters in a string atoi
            row = atoi(string_row.c_str());
            
            if (row >= 1 && row <= 3)
                break;
            cout << "You need to enter a column on the board between 1 and 3." << endl;
        }
        
        
        while (1) {
            cout << "Enter the column (Number only): ";
            cin >> string_col;
            col = atoi(string_col.c_str());
            
            if (col >= 1 && col <= 3)
                break;
            cout << "You need to enter a column on the board between 1 and 3." << endl;
        }
        
        if (board[row-1][col-1] == ' ') {
            board[row-1][col-1] = player;
            break;
        }
        
        else
            cout << "Someone is already in that spot." << endl << endl;
    }
}


char determine_cpu_choice (char player1) {
    char cpu_char;
    
    if (player1 == 'x' || player1 == 'X')
        cpuPiece.setCpuPiece('O');
    else
        cpuPiece.setCpuPiece('X');
    cpu_char = cpuPiece.getCpuPiece();
    
    return cpu_char;
}

char determine_player_choice (string s) {
    while (1) {
        char choice;
        cout << s << ", Would you like to be an X or an O? ";
        cin >> choice;
        
        //Converts to uppercase
        for(int i = 0; i < strlen(&choice); i++)
            choice = toupper(choice);
        
        while(choice != 'X' && choice != 'O'){
            cout << "Please enter either an X or an O: ";
            cin >> choice;
            for(int i = 0; i < strlen(&choice); i++)
                choice = toupper(choice);
            
            if(choice == 'X' || choice == 'O'){
                break;
            }
        }
        playerPiece.setPlayerPiece(choice);
        choice = playerPiece.getPlayerPiece();
        return choice;
    }
}


void play_game_1_player (char board[3][3], char player1, char cpu) {
    int moves = 0;
    while (moves < 9) {
        player_placement(board, player1);
        moves++;
        print_board(board);
        if (check_win(board)) {
            cout << endl;
            winnerPiece.setWinningPiece(player1);
            cout << winnerPiece.getWinningPiece() << " won!" <<endl;
            exit(1);
        }
        if (moves == 9)
            break;
        int where_to_move = pick_best_move(board, cpu, player1);
        int row = where_to_move / 10;
        int col = where_to_move % 10;
        
        board[row][col] = cpu;
        
        moves++;
        print_board(board);
        if (check_win(board)) {
            cout << endl;
            winnerPiece.setWinningPiece(cpu);
            cout << winnerPiece.getWinningPiece() << " won!" <<endl;
            exit(2);
        }
    }
    cout << endl;
    cout << "It's a draw!" << endl;
}

int main() {
    
    tic_tac_toe game;
    initalize_board(game.board);
    player1 = determine_player_choice("Hello");
    cpu = determine_cpu_choice(player1);
    print_board(game.board);
    
    play_game_1_player(game.board, player1, cpu);
    
    print_board(game.board);
    
    return 0;
}
