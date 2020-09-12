//
// Created by 宋子阳 on 2020-09-12.
//

#include "header.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        vector<vector<int>> edges(26);
        for(string& eq: equations){
            if(eq[1] == '='){
                edges[eq[0] -'a'].push_back(eq[3] - 'a');
                edges[eq[3] -'a'].push_back(eq[0] - 'a');
            }
        }

        for(string& eq: equations){
            if(eq[1] == '!'){
                if(search(edges, eq[0]-'a', eq[3]-'a')){
                    return false;
                }
            }
        }
        return true;


    }

    bool search(vector<vector<int>>& edges, int i, int j){
        vector<int> visited(26);
        queue<int> q;
        q.push(i);
        while(not q.empty()){
            int ele = q.front(); q.pop();
            if(ele == j) return true;
            visited[ele] = 1;
            for(int e: edges[ele]){
                if(visited[e] == 0){
                    q.push(e);
                }
            }
        }
        return false;

    }



};

int main(){
    vector<string> eqs = {"a==b","b!=a"};
    Solution s;
    cout<< s.equationsPossible(eqs) << endl;
}