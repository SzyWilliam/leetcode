//
// Created by 宋子阳 on 2020-09-10.
//
#include "header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        backtrack(result, current, candidates, 0, 0, target);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int candidate_index, int currentSum, int target){
        if(currentSum == target){
            result.push_back(current);
        }else if(currentSum > target){
            return;
        }else{
            int rest = target - currentSum;
            if(candidate_index >= candidates.size()) return;
            int up = rest / candidates[candidate_index];
            for(int i = 0; i <= up; i++){
                for(int j = 0 ; j < i; j++) current.push_back(candidates[candidate_index]);
                backtrack(result, current, candidates, candidate_index+1, currentSum + i * candidates[candidate_index], target);
                for(int j = 0; j < i; j++) current.pop_back();
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> res = s.combinationSum(candidates, 7);
    for(auto i : res){
        for(auto j: i){
            cout << j << ' ';
        }
        cout << endl;
    }
}