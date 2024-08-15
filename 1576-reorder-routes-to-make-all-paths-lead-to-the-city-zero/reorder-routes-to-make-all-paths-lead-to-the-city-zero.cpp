class Solution {
public:
int ans;
    int minReorder(int n, vector<vector<int>>& connections) {
        ios::sync_with_stdio(0); cin.tie(0);
        ans = 0;
        vector<vector<vector<int>>> graph(n, vector<vector<int>>());

        for(auto u: connections) {
           graph[u[0]].push_back(u);
           graph[u[1]].push_back(u);
        }

        dfs(0, -1, graph);
        return ans;
    }

    void dfs(int node, int parent, vector<vector<vector<int>>>& graph) {
        for(auto edge: graph[node]) {
            int a = edge[1];
            int b = edge[0];

            if(a == parent || b == parent) continue;
            if(b == node) {
                swap(a, b);
                ans++;
            }

            dfs(b, node, graph);
        }
    }
};