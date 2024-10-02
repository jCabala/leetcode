class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int[] pref = new int[n];

        pref[0] = nums[0];
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] + nums[i];

        int bck = 0, frt = 0, res = 0;
        while(frt < n) {
            int bckPref = bck > 0 ? pref[bck - 1] : 0;
            int sum = pref[frt] - bckPref;
            System.out.println(sum);
            if (sum >= target) {
                if (res == 0) res = frt - bck + 1;
                else res = Math.min(res, frt - bck + 1);
                bck++;
            } else frt++;
        }
        return res;
    }
}