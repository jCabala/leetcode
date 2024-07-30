class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios::sync_with_stdio(0); cin.tie(0);
        int lhs = 0, rhs = 0, resSum = 0, sum = 0;
        while(rhs < k) sum += nums[rhs++];
        resSum = sum;

        while(rhs < nums.size()) {
            sum = sum - nums[lhs] + nums[rhs];
            resSum = max(resSum, sum);

            rhs++;
            lhs++;
        }

        return (double) resSum / k; 
    }
};