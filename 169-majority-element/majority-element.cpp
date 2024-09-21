class Solution {
public:
    int majorityElement(vector<int>& nums) {
       map<int, int> hm;
       int n = nums.size();

       for(auto u: nums) {
            if (hm.contains(u)) {
                hm[u]++;
            } else {
                hm[u] = 1;
            }
       } 

       for (const auto& [key, value] : hm) {
        if (value > n/2) return key;
       }

       return -1;
    }
};