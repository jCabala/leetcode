class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
       vector<int> ans = {0, 1};
       int cur = 2, curPowOf2 = 1;
       while(cur <= n) {
            if (cur == 2 * curPowOf2) {
                ans.push_back(1);
                curPowOf2 *= 2;
            } else {
                ans.push_back(1 + ans[cur - curPowOf2]);
            }

            cur++;
       }

       return ans;
    }
};