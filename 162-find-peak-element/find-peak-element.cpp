class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0);
        int lo = 0;
        int hi = nums.size() - 1;

        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        while(lo <= hi) {
            int md = (hi + lo) / 2;
            cout << md << endl;
            int a = nums[md - 1];
            int b = nums[md + 1];

            if (nums[md] > a && nums[md] > b) return md;

            if (a > b) {
                hi = md;
            } else {
                lo = md;
            }
        }

        return -1;
    }
};