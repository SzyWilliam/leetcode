//
// Created by 宋子阳 on 2020-09-11.
//

#include "header.h"
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n, vector<int>());
        for(auto& iter: edges){
            G[iter[0]].push_back(iter[1]);
        }

        vector<int> root(n);
        for(int i = 0; i < n; i++) root[i] = i;

        //接下去就构造一个并查集
        vector<int> visited(n);
        queue<int> q;
        for(int i = 0; i < n; i++) q.push(i);
        while(not q.empty()){
            int ele = q.front(); q.pop();
            visited[ele] = 1;
            for(int i : G[ele]){
                root[i] = ele;
                if(visited[i] == 0){

                    q.push(i);
                }
            }
        }

        vector<int> ret;
        for(int i = 0; i < n; i++){
            if(root[i] == i){
                ret.push_back(i);
            }
        }

        return ret;

    }
};