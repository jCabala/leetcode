class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 1) return 1;
       if (nums.size() == 2) return 2;

       int it = 2, bck = 2;

       while (it < nums.size()) {
        int val = nums[it++];
        if (nums[bck - 1] != val || nums[bck - 2] != val) {
            nums[bck++] = val;
        }
       }
       
       return bck;
    }
};