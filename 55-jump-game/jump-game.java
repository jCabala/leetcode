class Solution {
    public boolean canJump(int[] nums) {
        int maxFront = 0;
        for(int i = 0; i < nums.length; i++) {
            if (i > maxFront) return false;
            maxFront = Math.max(maxFront, i + nums[i]);
            if (maxFront >= nums.length - 1) return true;
        }

        return true;
    }
}