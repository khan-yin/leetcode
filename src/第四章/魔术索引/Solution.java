package 第四章.魔术索引;

public class Solution {
    //类似分治法的思想，用二分
    public int binary_search(int[] nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (right - left) / 2 + left;
        int lfind = binary_search(nums, left, mid - 1);
        if (lfind != -1) {
            return lfind;
        } else if (nums[mid] == mid) {
            return mid;
        } else {
            return binary_search(nums, mid + 1, right);
        }
    }

    public int findMagicIndex(int[] nums) {
        //方法1——直接遍历
        // for(int i=0;i<nums.length;i++)
        // {
        //     if(nums[i]==i)
        //     {
        //         return i;
        //     }
        // }

        //方法2——跳跃减治
        // for(int i=0;i<nums.length;i++)
        // {
        //     if(nums[i]==i)
        //         return i;
        //     if(nums[i]>i)
        //         i=nums[i]-1;
        // }
        // return -1;

        //方法3——减治优化
        // for(int i=0;i<nums.length;i++)
        // {
        //     if(nums[i]==i)
        //         return i;
        //     if (nums[i] > i + 1) {
        //         //如果nums[i]大于i+1,我们就让i加上nums[i] - 1，
        //         // 这里减1的目的是为了抵消上面for循环中的i++。
        //         //这里判断的时候为什么是nums[i] > i + 1而不是
        //         //nums[i] > i ,因为如果num[i]只比i大1的话，
        //         //直接执行上面的i++就可以了，没必要再执行下面的计算
        //         i = nums[i] - 1;
        //     }

        // }
        // return -1;

        //方法4——二分思想，分治法
        return binary_search(nums, 0, nums.length - 1);


    }
}
