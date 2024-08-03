class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        set<vector<int>> res;
        unordered_map<int, vector<int>> dupe;

        for(int i = 0; i < grid.size(); ++i){
            if(res.find(grid[i]) != res.end()) {
                dupe[i] = grid[i];
            } 
            res.insert(grid[i]);
        }
        for(int i = 0; i < grid.size(); ++i){
            vector<int> temp;
            for(int j = 0; j <  grid.size(); ++j){
                temp.push_back(grid[j][i]);
            }
            if(res.find(temp) != res.end()) {
                for(auto& it: dupe){
                    if(it.second == temp){
                        ++count;
                    }
                }
                ++count;
                cout << i << " ";
            } 
        }


        return count;
    }
};