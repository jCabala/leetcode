class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       ios::sync_with_stdio(0); cin.tie(0);
       int numsIdx = 0;

       for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[numsIdx] = nums[i];
                numsIdx++;
            }
       }

       for (int i = numsIdx; i < nums.size(); i++) {
            nums[i] = 0;
       }
        
    }
};