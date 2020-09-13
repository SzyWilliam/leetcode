//
// Created by 宋子阳 on 2020-09-12.
//

#include "header.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> edges(N+1);
        for(auto& time: times){
            edges[time[0]].push_back(pair<int,int>(time[1], time[2]));
        }

        vector<int> len(N+1, 6000001);
        vector<int> settled(N+1);

        typedef pair<int, int> pii;
        //dijkstra algorithm
        len[K] = 0;

        for(int i = 1; i <= N; i++){
            //first construct the priority queue
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            for(int j = 1; j <= N; j++){
                if(not settled[j]){
                    pq.push(pii(len[j], j));
                }
            }

            //then pop the top element and calculate the shorter path
            pii ele = pq.top(); pq.pop();
            settled[ele.second] = 1;
            for(pii v: edges[ele.second]){
                len[v.first] = min(len[v.first], len[ele.second] + v.second);
            }
        }

        int max_len = *(max_element(len.begin()+1, len.end()));

        return max_len == 6000001 ? -1 : max_len;

    }
};

int main(){
    vector<vector<int>> time = {{2,1,1},{2,3,1},{3,4,1}};
    Solution s;
    cout << s.networkDelayTime(time, 4, 2);

}