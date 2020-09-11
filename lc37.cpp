//
// Created by 宋子阳 on 2020-09-10.
//

#include "header.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int ki = 0,kj = 0;
        for(ki = 0; ki < 9; ki++){
            for(kj = 0; kj < 9; kj++){
                if(board[ki][kj] == '.'){
                    solve(board, ki, kj);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board, int i, int j){
        for(int num = 1; num <= 9; num++){
            if(valid(board, i, j, num)){
                board[i][j] = num + '0';
                int ki = 0,kj = 0;
                for(ki = 0; ki < 9; ki++){
                    for(kj = 0; kj < 9; kj++){
                        if(board[ki][kj] == '.'){
                            solve(board, ki, kj);
                        }
                    }
                }

                board[i][j] = '.';
            }
        }
    }

    bool valid(vector<vector<char>>& board, int i, int j, int number){
        //col
        for(int j_prime = 0; j_prime < 9; j_prime++){
            if(board[i][j_prime]-'0' == number) return false;
        }
        //row
        for(int i_prime = 0; i_prime < 9; i_prime++){
            if(board[i_prime][j]-'0' == number) return false;
        }
        //square
        int col_start = (i/3)*3;
        int row_start = (j/3)*3;
        for(int k = col_start; k < col_start+3; k++){
            for(int m = row_start; m < row_start+3; m++){
                if(board[k][m]-'0' == number) return false;
            }
        }
        return true;
    }
};