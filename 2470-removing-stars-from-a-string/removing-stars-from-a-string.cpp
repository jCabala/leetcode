class Solution {
public:
    string removeStars(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        stack<char> chars;

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c != '*') {
                chars.push(c);
            } else if (!chars.empty()) {
                chars.pop();
            }
        }

        string ans;
        ans.resize(chars.size());
        size_t back = ans.size() - 1;

        while(!chars.empty()){
            ans[back--] = chars.top();
            chars.pop();
        }

        return ans;
    }
};