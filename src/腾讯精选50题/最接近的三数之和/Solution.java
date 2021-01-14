package 腾讯精选50题.最接近的三数之和;

import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int len = nums.length;
        Arrays.sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < len; i++) {
            int left = i + 1;
            int right = len - 1;
            // System.out.println(left);
            // System.out.println(right);
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.abs(sum - target) < Math.abs(ans - target)) {
                    ans = sum;
                    // while(left<right&&nums[left]==nums[left-1]) left++;
                    // while(left<right&&nums[left]==nums[left-1]) right--;
                    // left++;
                    // right--;
                } else if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else
                    return ans;
            }
        }
        return ans;
    }
}
