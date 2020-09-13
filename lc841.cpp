//
// Created by 宋子阳 on 2020-09-13.
//

#include "header.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        int remaining = n;

        queue<int> q;
        q.push(0);

        while(not q.empty()){
            int room = q.front(); q.pop();
            if(visited[room] == 0){
                visited[room] = 1;
                remaining--;
            }

            for(int key: rooms[room]){
                if(visited[key] == 0){
                    q.push(key);
                }
            }
        }
        return remaining == 0;

    }
};

int main() {
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    Solution s;
    s.canVisitAllRooms(rooms);
}