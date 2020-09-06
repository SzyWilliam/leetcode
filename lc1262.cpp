//
// Created by 宋子阳 on 2020-09-06.
//

//DP and Math
/*
 * 初步的想法是dp 但是发现n2肯定超时
 * 接下去想到mod3分成三个数组，然后找出mod1 和 mod2的两个数组，写出表达式
 * dp[m1][m2] =
 * max(
 *      dp[m1-1][m2-1] + a1[m1] + a2[m2]
 *      dp[m1-3][m2] + a1[m1] + a1[m1-1] + a1[m1-2]
 *      dp[m1][m2-3] + a2[m2] + a2[m2-1] + a2[m2-2]
 * )
 * 其中dp[k1][k2]表示mod1数组前k1位数字和mod2数组前k2位数字最大的三倍数
 * 注意一下边界条件（k1 or k2 = -1)
 *
 * 但是即使如此，还是超时了，因此再次考虑优化
 * 发现，如果两个数组分别三个三个先自己加起来，一定满足最大的条件，具体来说就是
 * 假设mod1数组有m1个数字，mod2数组有m2个数字 m1>m2
 * mod1和mod2数组的 m1-m2 + 3位数之后的所有数字可以先三个三个加起来
 * 然后对这两个数组剩下的东西进行dp就可以获得最大值
 *
 * */

#include "header.h"

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> m[3];
        for(int num: nums){
            m[num%3].emplace_back(num);
        }
        int sum_m0 = 0;

        for(int num0: m[0]) sum_m0 += num0;

        int m2_size = m[2].size();
        int m1_size = m[1].size();
        sort(m[1].begin(), m[1].end());
        sort(m[2].begin(), m[2].end());

        int sum1 = 0;
        int remaining = max(m1_size, m2_size) - min(m1_size, m2_size) + 3;
        int index_m1, index_m2;
        for(index_m1 = m1_size-1; index_m1 > remaining + 3; index_m1 -= 3){
            sum1 += m[1][index_m1] + m[1][index_m1-1] + m[1][index_m1-2];
        }
        for(index_m2 = m2_size-1; index_m2 > remaining + 3; index_m2 -= 3){
            sum1 += m[2][index_m2] + m[2][index_m2-1] + m[2][index_m2-2];
        }

        vector<vector<int>> dp(index_m1+1, vector<int>(index_m2+1, 0));

        return solve(dp, m[1], m[2], index_m1, index_m2) + sum_m0 + sum1;
    }

    int solve(vector<vector<int>>& dp, vector<int>& m1, vector<int>&m2, int k1, int k2){

        if(k1 == -1 and k2 > 0){
            int s = 0;
            for(int i = k2-2; i >= 0; i-=3){
                s += m2[i] + m2[i+1] + m2[i+2];
            }
            return s;
        }

        if(k1 > 0 and k2 == -1){
            int s = 0;
            for(int i = k1-2; i >= 0; i-=3){
                s += m1[i] + m1[i+1] + m1[i+2];
            }
            return s;
        }

        if(k1 < 0 or k2 < 0) return 0;
        if(dp[k1][k2] > 0) return dp[k1][k2];
        else{
            dp[k1][k2] = 0;
            if(k1 >= 0 and k2 >= 0)
                dp[k1][k2] = max(dp[k1][k2], solve(dp, m1, m2, k1-1, k2-1) + m1[k1] + m2[k2]);

            if(k1 >= 2)
                dp[k1][k2] = max(dp[k1][k2], solve(dp, m1, m2, k1-3, k2) + m1[k1-2] + m1[k1-1] + m1[k1]);

            if(k2 >= 2)
                dp[k1][k2] = max(dp[k1][k2], solve(dp, m1, m2, k1, k2-3) + m2[k2-2] + m2[k2-1] + m2[k2]);

            return dp[k1][k2];
        }
    }
};