class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numOccurences = 0;
        int back = nums.size() - 1;
        int front = 0;

        while(back >= front)
            if (nums[back] == val) {
                numOccurences++;
                back--;
            } else if (nums[front] == val) {
                numOccurences++;
                nums[front] = nums[back--];
            } else {
                front++;
            }

        return nums.size() - numOccurences;
    }
};