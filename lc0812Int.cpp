//
// Created by 宋子阳 on 2020-09-10.
//

#include "header.h"

class Solution {
public:
    int sum = 0;
    int totalNQueens(int n) {
        vector<string> current(n, string(n, '.'));
        vector<vector<string>> result;
        backtrack(current, 0, n);
        return sum;

    }

    void backtrack(vector<string>& current, int line, int N){
        if(line == N){
            sum++;
            return;
        }else{

            for(int i = 0; i < N; i++){
                if(isAvailable(current, line, i, N)){
                    current[line][i] = 'Q';
                    backtrack(current, line+1, N);
                    current[line][i] = '.';
                }
            }
        }
    }

    bool isAvailable(vector<string>& current, int i, int j, int N){
        for(int j_prime = 0; j_prime < N; j_prime++){
            if(current[i][j_prime] == 'Q'){
                return false;
            }
        }
        for(int i_prime = 0; i_prime < N; i_prime++){
            if(current[i_prime][j] == 'Q'){
                return false;
            }
        }
        for(int k = 0; k < N; k++){
            if(i+k < N and j+k < N and current[i+k][j+k] == 'Q') return false;
            if(i-k >= 0 and j+k < N and current[i-k][j+k] == 'Q') return false;
            if(i+k < N and j-k >= 0 and current[i+k][j-k] == 'Q') return false;
            if(i-k >= 0 and j-k >= 0 and current[i-k][j-k] == 'Q') return false;
        }
        return true;
    }
};

class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {

        return result;
    }







};

int main(){
    Solution s;
    s.solveNQueens(4);
}