class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      ios::sync_with_stdio(0); cin.tie(0);
      int res = longestOnes(nums, 1);

      if (res == 1) {
        return 0;
      } else {
        return res - 1;
      }
    }

    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(0); cin.tie(0);
        queue<int> q;
        int curSum = 0, curFlipped = 0, maxSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curSum++;
            } else if (q.size() < k) {
                curSum++;
                q.push(i);
            } else if (k != 0){
                int idx = q.front();
                q.pop();
                curSum = i - idx;
                q.push(i);
            } else {
                curSum = 0;
            }

            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};