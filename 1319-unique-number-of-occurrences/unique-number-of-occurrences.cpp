class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        ios::sync_with_stdio(0); cin.tie(0);
        int negs[1005], poss[1005];
        vector<int> occ;

        for(int i = 0; i <= 1000; i++) negs[i] = poss[i] = 0;

        for (int u: arr) {
            if (u >= 0) {
                poss[u]++;
            } else {
                negs[-1 * u]++;
            }
        }

        for (int i = 0; i <= 1000; i++) {
            if (poss[i] != 0) {
                occ.push_back(poss[i]);
            }

            if (negs[i] != 0) {
                occ.push_back(negs[i]);
            }
        }
        
        sort(occ.begin(), occ.end());
        for(int i = 0; i < occ.size() - 1; i++) {
            if (occ[i] == occ[i + 1]) {
                return false;
            }
        }

        return true;
    }
};