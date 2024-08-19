class Solution {
public:
    // We want h >= sumOverPiles(pile / k) + sumOverPiles(pile % k)
    int minEatingSpeed(vector<int>& piles, int h) {
        ios::sync_with_stdio(0); cin.tie(0);
        int lo = 1, hi = 1;
        for(int p: piles) hi = max(hi, p);

        int ans = -1;
        while (lo <= hi) {
            int md = (lo + hi) / 2;

            int isHigher = timeHigherThan(piles, md, h);
            if (isHigher) {
                lo = md + 1;
            } else {
                ans = md;
                hi = md - 1;
            }
        }

        return ans;
    }

    bool timeHigherThan(vector<int>& piles, int k, int h) {
        int ans = 0;
        for(auto p: piles) {
            ans += p / k + (p % k == 0 ? 0 : 1);
            if (ans > h) return 1;
        }
        return ans > h;
    }
};