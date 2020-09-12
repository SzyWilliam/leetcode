//
// Created by 宋子阳 on 2020-09-12.
//

#include "header.h"
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int j_prime = 0; j_prime < n; j_prime++){
                        if(j_prime != j and grid[i][j_prime] == 1){
                            count++;
                            goto out;
                        }
                    }

                    for(int i_prime = 0; i_prime < m; i_prime++){
                        if(i_prime != i and grid[i_prime][j] == 1){
                            count++;
                            break;
                        }
                    }
                }
                out:
                continue;

            }
        }

        return count;
    }
};