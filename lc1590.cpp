//
// Created by 宋子阳 on 2020-09-21.
//

#include "header.h"

/**
 * 在计算出前缀和之后
 * 遍历前n项的内容，每遍历一个元素，都把这个元素加入到hashmap中
 * 接下去遍历的时候可以查找hashmap来完成i，j之间范围的需求
 * 这样的话就用了n的空间将n2的复杂度降低到了n
 */

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        typedef long long ll;
        int n = nums.size();
        vector<ll> preSum(n+1);
        ll acc = 0;
        for(int i = 0; i < n; i++){
            acc += nums[i];
            preSum[i+1] = acc % p;
        }

        int mod = acc % p;
        if(mod == 0) return 0;

        int res_len = nums.size();
        unordered_map<ll, int> m;
        for(int i = 0; i <= n; i++){
            m[preSum[i]] = i;
            int res_mod = (preSum[i]-mod+p) % p;
            if(m.count(res_mod) == 1){
                res_len = min(res_len, i - m[res_mod]) ;
            }
        }
        return res_len == nums.size() ? -1 : res_len;
    }
};