//
// Created by 宋子阳 on 2020-09-10.
//

#include "header.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> freq;
        for(int num: nums){
            if(freq.count(num) == 0){
                freq.insert(pair<int, int>(num, 0));
            }
            freq[num]++;
        }

        vector<pair<int, int>> candidates;
        candidates.insert(candidates.begin(), freq.begin(), freq.end());

        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, candidates, 0);
        result.push_back(vector<int>());
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<pair<int,int>>& candidates,
            int start_index){
        pair<int,int> ele = candidates[start_index];
        for(int count = 0; count <= ele.second; count++){
            for(int i = 0; i < count; i++) current.push_back(ele.first);
            if(count!=0) result.push_back(current);
            if(start_index+1 < candidates.size()){
                backtrack(result, current, candidates, start_index+1);
            }
            for(int i = 0; i < count; i++) current.pop_back();
        }
    }
};