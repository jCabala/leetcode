class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int it1 = 0, it2 = numbers.size() - 1;

        while(true)
            if (numbers[it1] + numbers[it2] == target) return {it1 + 1, it2 + 1};
            else if (numbers[it1] + numbers[it2] > target) it2--;
            else it1++;

        return {};
    }
};