class Solution {
public:
    int maxArea(vector<int>& h) {
        int rhs = h.size() - 1;
        int lhs = 0;
        int res = 0;

        while(rhs != lhs) {
            res = max(res, (rhs - lhs) * min(h[lhs], h[rhs]));

            if (h[lhs] <= h[rhs]) {
                lhs++;
            } else {
                rhs--;
            }
        }

        return res;
    }
};

// maximize min(h[i], h[j]) * |i - j|