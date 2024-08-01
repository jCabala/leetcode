class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios::sync_with_stdio(0); cin.tie(0);
        int cur = 0, res = 0;

        for(int i = 0; i < gain.size(); i++) {
            cur += gain[i];
            res = max(res, cur);
        }

        return res;
    }
};