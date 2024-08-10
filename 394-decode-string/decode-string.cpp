class Solution {
public:
    string decodeString(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        stack<int> indexes;
        stack<int> values;
        vector<char> ans;

        int it = 0;
        int curVal = 0;
        while (it < s.size()) {
            if (s[it] >= 'a' && s[it] <= 'z') {
                ans.push_back(s[it]);
                it++;
            } else if (s[it] == '[') {
                indexes.push(it);
                values.push(curVal);
                curVal = 0;
                it++;
            } else if (s[it] >= '0' && s[it] <= '9') {
                curVal = curVal * 10 + (s[it] - '0');
                it++;
            } else if (s[it] == ']') {
                int topVal = values.top();
                values.pop();
                if (topVal == 1) {
                    indexes.pop();
                    it++;
                } else {
                    values.push(topVal - 1);
                    it = indexes.top() + 1;
                }
            }
        }

        return string(ans.begin(), ans.end());
    }
};