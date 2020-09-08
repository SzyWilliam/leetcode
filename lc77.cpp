//
// Created by 宋子阳 on 2020-09-08.
//
#include "header.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> candidates(n);
        for(int i = 0; i < n; i++) candidates[i] = i+1;
        helper(result, vector<int>(), candidates, -1, k);
        return result;

    }

    void helper(vector<vector<int>>& result, vector<int> current, vector<int> candidates, int start_index, int n){
        if(current.size() == n){
            vector<int> a = current;
            result.push_back(a);
        }else{
            for(int i = start_index + 1; i < candidates.size(); i++){
                int ele = candidates[i];
                current.push_back(ele);
                helper(result, current, candidates, i, n);
                current.pop_back();
            }
        }
    }
};