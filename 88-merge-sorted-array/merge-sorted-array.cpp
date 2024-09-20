class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int it1 = 0;
        int it2 = 0;

        while(it1 < m && it2 < n)
            if (nums1[it1] < nums2[it2]) ans.push_back(nums1[it1++]);
            else ans.push_back(nums2[it2++]);


        while(it1 < m) ans.push_back(nums1[it1++]);
        while(it2 < n) ans.push_back(nums2[it2++]);

        for (int i = 0; i < n + m; i++) nums1[i] = ans[i];
    }
};