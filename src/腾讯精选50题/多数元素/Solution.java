package 腾讯精选50题.多数元素;

public class Solution {
    public int majorityElement(int[] nums) {
        //摩尔投票法
        int cand_num = nums[0], count = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (cand_num == nums[i])
                ++count;
            else if (--count == 0) {
                cand_num = nums[i];
                count = 1;
            }
        }
        return cand_num;
    }
}
