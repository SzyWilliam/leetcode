//
// Created by 宋子阳 on 2020-09-12.
//

#include "header.h"

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int index = 0;
        map<string, int> m;
        for(auto& i: tickets){
            for(string& j: i){
                if(m.count(j) == 0){
                    m.insert(pair<string, int>(j, index++));
                }
            }
        }

        vector<vector<string>> edge(index);
        for(auto& iter: tickets){
            edge[m[iter[0]]].push_back(iter[1]);
        }
        for(auto& iter: edge){
            sort(iter.begin(), iter.end());
        }

        vector<string> route;
        vector<int> visited(index);
        string first = "JFK";
        route.push_back(first);
        backtrack(route, edge, first, m, tickets.size()+1);
        return res;

    }
    bool end = false;
    vector<string> res;

    void backtrack(vector<string>& route, vector<vector<string>>& edge, string& prev, map<string, int>& m, int route_size){
        if(end) return;
        if(route.size() == route_size){
            res.insert(res.begin(), route.begin(), route.end());
            end = true;
            return;
        }

        vector<string>& ed = edge[m[prev]];
        for(int i = 0; i < ed.size(); i++){
            string next = ed[i];
            route.push_back(next);
            ed.erase(ed.begin() + i);
            backtrack(route, edge, next, m, route_size);
            ed.insert(ed.begin() + i, next);
            route.pop_back();

            if(end) return;
        }

    }
};

int main() {
    vector<vector<string>> tickets = {{"JFK", "KUL"},
                                      {"JFK", "NRT"},
                                      {"NRT", "JFK"}};
    Solution s;
    s.findItinerary(tickets);
}