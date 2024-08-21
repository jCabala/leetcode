class Solution {
public:
    int rob(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0);
        if (nums.size() == 1) return nums[0];
        vector<int> dp = {nums[0], max(nums[0], nums[1])};

        int ans = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            int cur = max(dp[i-1], dp[i-2] + nums[i]);
            ans = max(ans, cur);
            dp.push_back(cur);
        }

        return ans;
    }
};