class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int res = 0;
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (prev_end > intervals[i][0]) {
                ++res;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return res;
    }
};