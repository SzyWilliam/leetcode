//
// Created by 宋子阳 on 2020-09-13.
//

#include "header.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> use(board.size(), vector<int>(board[0].size()));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    use[i][j] = 1;
                    if(backtrack(board, word, 1, i, j, use)){
                        return true;
                    }
                    use[i][j] = 0;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int word_index, int i, int j, vector<vector<int>>& use){
        if(word_index == word.size()) return true;
        else{
            bool flag = false;
            char target = word[word_index];
            if(i-1>=0 and board[i-1][j] == target and use[i-1][j] == 0){
                use[i-1][j] = 1;
                flag = backtrack(board, word, word_index+1, i-1, j, use);
                use[i-1][j] = 0;
                if(flag) return true;
            }
            if(i+1 < board.size() and board[i+1][j] == target and use[i+1][j] == 0){
                use[i+1][j] = 1;
                flag = backtrack(board, word, word_index+1, i+1, j, use);
                use[i+1][j] = 0;
                if(flag) return true;
            }
            if(j-1 >= 0 and board[i][j-1] == target and use[i][j-1] == 0){
                use[i][j-1] = 1;
                flag = backtrack(board, word, word_index+1, i, j-1, use);
                use[i][j-1] = 0;
                if(flag) return true;
            }
            if(j+1 < board[0].size() and board[i][j+1] == target and use[i][j+1] == 0){
                use[i][j+1] = 1;
                flag = backtrack(board, word, word_index+1, i, j+1, use);
                use[i][j+1] = 0;
                if(flag) return true;
            }
            return false;
        }
    }
};