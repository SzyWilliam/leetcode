//
// Created by 宋子阳 on 2020-09-07.
//
#include "header.h"


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        //统计所有数字的出现频率
        for(int num: nums){
            if(freq.count(num) == 0){
                freq.insert(pair<int,int>(num, 0));
            }
            freq[num]++;
        }

        //将这些出现频率建立成一个最大堆，然后一个个给pop出来
        int size = freq.size();
        vector<pair<int, int>> heap;
        //首先变成一个二叉树
        for(auto iter = freq.begin(); iter != freq.end(); ++iter){
            heap.emplace_back(*iter);
        }
        //接下去将每一个子树变成一个最大堆
        for(int i = size/2; i >= 0; i--){
            porcelate_down(heap, i);
        }

        //堆已经建立好了，接下来就是找到前k个最大的元素
        vector<int> result;
        for(int i = 0; i < k; i++){
            pair<int,int> ele = heap[0];
            heap[0] = heap[heap.size()-1];
            heap.pop_back();
            porcelate_down(heap, 0);
            result.push_back(ele.first);
        }
        return result;




    }

    void porcelate_down(vector<pair<int, int>>& heap, int index){
        //将heap[index]元素调整到合适的位置上
        int key = heap[index].second;
        pair<int,int> ele = heap[index];
        int child;
        for(child = index*2; child < heap.size(); ){
            if(child+1 < heap.size() and heap[child].second < heap[child+1].second)
                child = child+1;
            if(key < heap[child].second){
                heap[child/2] = heap[child];
                child *= 2;
            }else{
                break;
            }
        }
        heap[child/2] = ele;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,1,1,2,2,3};
    s.topKFrequent(arr, 2);
}