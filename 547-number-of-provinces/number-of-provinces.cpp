class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios::sync_with_stdio(0); cin.tie(0);
        vector<bool> visited(isConnected.size(), false);
        vector<vector<int>> graph(isConnected.size(), vector<int>());

        for(int i = 0; i < isConnected.size(); i++)
            for(int j = 0; j < isConnected.size(); j++) {
                if (i == j) continue;
                if(isConnected[i][j]) {
                    graph[i].push_back(j);
                }
            }

        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++) if(!visited[i]) {
            ans++;
            dfs(i, graph, visited);
        }
        return ans;
    }

    
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        if(visited[node]) return;

        visited[node] = true;
        for(auto u: graph[node]) dfs(u, graph, visited);
    }
};