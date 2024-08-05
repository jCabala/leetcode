class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        ios::sync_with_stdio(0); cin.tie(0);
        stack<int> cur;
        for(int u: asteroids) {
            if (cur.empty()) {
                cur.push(u);
            } else {
                bool pushMe = true;
                while(!cur.empty()) {
                    int tp = cur.top();
                    if (tp < 0 || u > 0) {
                        break;
                    } else if (abs(tp) == abs(u)) {
                        cur.pop();
                        pushMe = false;
                        break;
                    } else if (abs(tp) > abs(u)) {
                        pushMe = false;
                        break;
                    } else {
                        cur.pop();
                    }
                }

                if (pushMe) cur.push(u);
            }
        }

        vector<int> ans;
        while(!cur.empty()) {
            ans.push_back(cur.top());
            cur.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};