class Solution {
public:
    int maxArea(vector<int>& h) {
        ios::sync_with_stdio(0); cin.tie(0);
        int beg = 0, end = h.size() - 1;
        int ans = (end - beg) * min(h[beg], h[end]);

        while(beg < end) {
            ans = max(ans, (end - beg) * min(h[beg], h[end]));
            if (h[beg] > h[end]) {
                end--;
            } else {
                beg++;
            }
        }

        return ans;
    }
};