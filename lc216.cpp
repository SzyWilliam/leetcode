//
// Created by 宋子阳 on 2020-09-10.
//

#include "header.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, 1, 0, k, n);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, int starts_num, int  current_sum, int remaining_num, int target){
        if(remaining_num == 0 and target == current_sum){
            result.push_back(current);
        }else if(remaining_num < 0 or target < current_sum){
            return;
        }else{
            for(int num = starts_num;  num <= 9; num++){
                current.push_back(num);
                backtrack(result, current, num+1, current_sum + num, remaining_num-1, target);
                current.pop_back();
            }
        }
    }


};