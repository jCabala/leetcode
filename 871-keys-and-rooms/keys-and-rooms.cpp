class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ios::sync_with_stdio(0); cin.tie(0);
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);

        bool res = true;
        for(auto u: visited) res &= u;
        return res;
    }

    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited) {
        if(visited[node]) return;

        visited[node] = true;
        for(auto u: rooms[node]) dfs(u, rooms, visited);
    }
};