//
// Created by 宋子阳 on 2020-09-10.
//
/**
 * 回溯算法
 * 关键问题是，这个题目可能会出现重复的情况，因此要排除相应的情况
 * 代码中选择了比较简单的一种方式，即通过set自带的方式
 *
 * 更加朴素的一种方式
 * 采用hash，将每个元素的出现次数统计一下，放在freq中
 * freq[i] = k
 * i元素出现了k次
 * 接下去进行回溯的时候
 * for i in freq[candidates[index]]:
 *  search(index+1, target - i * candidates[index];
 */
#include "header.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result;

        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i++){
            vector<int> current;
            search(result, current, 0, candidates, i, target);
        }
        vector<vector<int>> ret;
        ret.assign(result.begin(), result.end());
        return ret;
    }

    void search(set<vector<int>>& result, vector<int>& current, int currentSum, vector<int>& candidates, int candidate_start_index, int target){
        //P(candidate_start_index)
        if(currentSum == target) result.insert(current);
        else if(currentSum > target){
            return;
        }else{

            for(int i = candidate_start_index; i < candidates.size(); i++){
                int ele = candidates[candidate_start_index];
                current.push_back(ele);
                search(result, current, currentSum + ele, candidates, i+1, target);
                current.pop_back();
            }
        }
    }


};

int main(){
    Solution s;
    vector<int> candidates  = {10,1,2,7,6,1,5};
    s.combinationSum2(candidates, 8);
}