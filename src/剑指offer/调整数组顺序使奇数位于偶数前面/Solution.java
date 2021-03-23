package 剑指offer.调整数组顺序使奇数位于偶数前面;

public class Solution {
    public int[] exchange(int[] nums) {
        int[] newnums = new int[nums.length];
        int i = 0;
        int j = nums.length - 1;
        for (int num : nums) {
            if ((num & 1) == 1)
                newnums[i++] = num;
            else
                newnums[j--] = num;
        }
        return newnums;
    }
}
