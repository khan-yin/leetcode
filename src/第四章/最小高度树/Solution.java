package 第四章.最小高度树;

import java.util.Arrays;

public class Solution {

    //前序遍历
    public static TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(nums[nums.length / 2]);
        root.left = sortedArrayToBST(Arrays.copyOfRange(nums, 0, nums.length / 2));
        root.right = sortedArrayToBST(Arrays.copyOfRange(nums, nums.length / 2 + 1, nums.length));
        return root;
    }

    public TreeNode sortedArrayToBST2(int[] nums) {
        // if(nums.length==0){ return null;}
        // TreeNode root = new TreeNode(nums[nums.length/2]);
        // root.left=sortedArrayToBST(Arrays.copyOfRange(nums,0, nums.length/2));
        // root.right=sortedArrayToBST(Arrays.copyOfRange(nums,nums.length/2+1,nums.length));
        // return root;
        return makeroot(nums, 0, nums.length - 1);
    }

    public TreeNode makeroot(int[] nums, int left, int right) {
        if (left > right) {
            return null;
        }
        int mid = (right - left) / 2 + left;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = makeroot(nums, left, mid - 1);
        root.right = makeroot(nums, mid + 1, right);
        return root;
    }

}
