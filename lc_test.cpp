//
// Created by 宋子阳 on 2020-09-19.
//

#include "header.h"


class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> freq(n, 0);
        for(auto& iter: requests){
            for(int i = iter[0]; i <= iter[1]; i++){
                freq[i]++;
            }
        }

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());
        int sum = 0;
        int mod = 1000000007;
        for(int i = 0; i < n; i++){
            sum = (sum + freq[i]*nums[i]) % mod;
        }
        return sum;


    }
};