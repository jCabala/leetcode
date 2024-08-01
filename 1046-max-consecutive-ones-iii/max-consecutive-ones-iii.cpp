class Solution {
public:
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

            printf("(%d, %d)", i, curSum);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};