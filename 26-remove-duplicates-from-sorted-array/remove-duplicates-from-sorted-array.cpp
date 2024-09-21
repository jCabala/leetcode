class Solution {
public:
    bool isPresent[201];
    int removeDuplicates(vector<int>& nums) {
        int front = 0, back = nums.size() - 1;
        int size = 0;

        while(front <= back) {
            if (isPresent[nums[back] + 100]) {
                back--;
            } else if (isPresent[nums[front] + 100]) {
                nums[front] = nums[back--];
            } else {
                isPresent[nums[front] + 100] = true;
                front++;
                size++;
            }
        }

        sort(nums.begin(), nums.begin() + size);
        return size;
    }
};