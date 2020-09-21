//
// Created by 宋子阳 on 2020-09-21.
//

#include "header.h"
//差分进行统计和贪心算法
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> freq(n+1, 0);

        for(auto& request: requests){
            freq[request[0]]++;
            freq[request[1]+1]--;
        }

        for(int i = 1; i <= n; i++){
            freq[i] += freq[i-1];
        }

        sort(freq.begin(), freq.end(), greater<>());
        sort(nums.begin(), nums.end(), greater<>());

        int sum = 0;
        int mod = 1000000007;
        for(int i = 0; i < n; i++){
            sum = (sum + freq[i]*nums[i]) % mod;
        }
        return sum;


    }
};
