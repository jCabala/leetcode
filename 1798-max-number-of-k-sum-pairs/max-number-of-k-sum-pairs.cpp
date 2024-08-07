class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ios::sync_with_stdio(0); cin.tie(0);
        sort(nums.begin(), nums.end());
        int res = 0;
        int lhs = 0, rhs = nums.size() - 1;

        while(lhs < rhs) {
            int sum = nums[lhs] + nums[rhs];
            if (sum == k) {
                res++;
                lhs++;
                rhs--;
            } else if (sum > k) {
                rhs--;
            } else {
                lhs++;
            }
        }

        return res;
    }
};