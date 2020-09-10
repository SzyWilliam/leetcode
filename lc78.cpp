//
// Created by 宋子阳 on 2020-09-10.
//

#include "header.h"
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, nums, 0);
        result.push_back(vector<int>());
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int start_index){

        for(int i = start_index; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            result.push_back(current);
            backtrack(result, current, candidates, i+1);
            current.pop_back();
        }
    }
};