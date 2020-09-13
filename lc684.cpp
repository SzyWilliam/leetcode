//
// Created by 宋子阳 on 2020-09-13.
//

#include "header.h"


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> G(n+1);

        for(auto& iter: edges){
            G[iter[0]].push_back(iter[1]);
            G[iter[1]].push_back(iter[0]);
        }


        for(auto iter = edges.rbegin(); iter != edges.rend(); ++iter){
            vector<int> e = *iter;
            G[e[0]].erase(find(G[e[0]].begin(), G[e[0]].end(), e[1]));
            G[e[1]].erase(find(G[e[1]].begin(), G[e[1]].end(), e[0]));
            if(isTree(G)){
                return e;
            }
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        return vector<int>();

    }

    bool isTree(vector<vector<int>>& G){
        vector<int> visited(G.size()+1);
        bool noCircle = true;
        dfs(G, visited, 0, 1, noCircle);
        if(!noCircle) return false;
        for(int i = 1; i < G.size(); i++){
            if(visited[i] == 0) return false;
        }
        return true;

    }

    void dfs(vector<vector<int>>& G, vector<int>& visited, int prev, int i, bool& noCircle){
        if(visited[i] == 1){
            noCircle = false;
            return;
        }else{
            visited[i] = 1;
            for(int v: G[i]){
                if(v == prev) continue;
                else{
                    dfs(G, visited, i, v, noCircle);
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges  ={{1,2},{2,3},{3,4},{1,4},{1,5}};
    cout << (s.findRedundantConnection(edges))[0];
}