//
// Created by 宋子阳 on 2020-09-18.
//
#include "header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(res, current, nums, nums.size());
        vector<vector<int>> ret;
        ret.insert(ret.begin(), res.begin(), res.end());
        return ret;

    }

    void backtrack(set<vector<int>>& res, vector<int>& current,
                   vector<int>& candidates, int n){
        if(current.size() == n and candidates.size() == 0){
            res.insert(current);
        }else{
            for(int i = 0; i < candidates.size(); i++){
                int ele = candidates[i];
                candidates.erase(candidates.begin() + i);
                current.push_back(ele);
                backtrack(res, current, candidates, n);
                current.pop_back();
                candidates.insert(candidates.begin() + i, ele);
            }
        }

    }


};