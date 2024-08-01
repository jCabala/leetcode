class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie();
        int prefSum = 0;
        int sufSum = 0;
        for(int u: nums) sufSum += u;

        for(int i = 0; i < nums.size(); i++) {
            int u = nums[i];
            sufSum -= u;
            if(prefSum == sufSum) {
                return i;
            }
            prefSum += u;
        }

        return -1;
    }
};