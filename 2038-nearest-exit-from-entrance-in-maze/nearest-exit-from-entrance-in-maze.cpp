class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int min_path = INT_MAX;
        deque<vector<int>> go_to_lab;
        go_to_lab.push_back({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        int size = maze.size() - 1, size1 = maze[0].size() - 1;
        while(!go_to_lab.empty())
        {
            auto el = go_to_lab.front();
            if(el[0] == 0 || el[0] == size || el[1] == 0 || el[1] == size1)
            {
                if(el[0] != entrance[0] || el[1] != entrance[1])
                    return min(min_path, el[2]);
            }
            
            if(el[0] + 1 <= size && maze[el[0] + 1][el[1]] == '.')
            {
                maze[el[0] + 1][el[1]] = '+';
                go_to_lab.push_back({el[0] + 1, el[1], el[2] + 1});
            }
            if(el[0] - 1 >= 0 && maze[el[0] - 1][el[1]] == '.')
            {
                maze[el[0] - 1][el[1]] = '+';
                go_to_lab.push_back({el[0] - 1, el[1], el[2] + 1});
            }
            if(el[1] + 1 <= size1 && maze[el[0]][el[1] + 1] == '.')
            {
                maze[el[0]][el[1] + 1] = '+';
                go_to_lab.push_back({el[0], el[1] + 1, el[2] + 1});
            }
            if(el[1] - 1 >= 0 && maze[el[0]][el[1] - 1] == '.')
            {
                maze[el[0]][el[1] - 1] = '+';
                go_to_lab.push_back({el[0], el[1] - 1, el[2] + 1});
            }
            go_to_lab.pop_front();
        }
        return min_path == INT_MAX ? -1 : min_path;
    }
};