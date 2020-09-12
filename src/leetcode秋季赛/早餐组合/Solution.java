package leetcode秋季赛.早餐组合;

import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
//        int[] staple = {10,1};//[][10,1]
//
//
//        int[] drinks = {8,9,10};
//        int x = 9;
//        int[] staple = {10,10,5};//[]
//
//        int[] drinks = {10,10,10};
//        int x = 6;
        int[] staple = {2,1,1};//[]

        int[] drinks = {8,9,5,1};
        int x = 9;
//        int[] staple = {10,20,5};//[]
//
//        int[] drinks = {5,5,5,2};
//        int x = 6;
//        Arrays.sort(drinks);
        System.out.println(solution.breakfastNumber(staple,drinks,x));
//        System.out.println(solution.binarySearch2(drinks,x));
    }

    public static int lower_bound(int[] arr, int begin, int end, int tar) {
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            // 当 mid 的元素小于 tar 时
            if(arr[mid] < tar)
                // begin 为 mid + 1, arr[begin] 的值会小于或等于 tar
                begin = mid + 1;
                // 当 mid 的元素大于等于 tar 时
            else if(arr[mid] >= tar)
                end = mid;
        }
        return begin;
    }

    public static int upper_bound(int[] arr, int tar) {
        int begin=0;
        int end=arr.length;
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            if(arr[mid] <= tar)
                begin = mid + 1;
            else if(arr[mid] > tar)
                end = mid;
        }
        return begin;
    }

    public int breakfastNumber(int[] staple, int[] drinks, int x) {
        long cnt=0;
        Arrays.sort(staple);
        Arrays.sort(drinks);
        for(int i:staple)
        {
            if(i>x){
                break;
            }
            else{
                int index = upper_bound(drinks, x-i);

                System.out.println(index);
                System.out.println("x");
                cnt+=index;


            }

        }
        return  (int) (cnt % 1000000007 );
    }

//    public static int binarySearch2(int[] nums, int key) {
//        if(key<=0)
//        {
//            return -1;
//        }
//        int l = 0, h = nums.length - 1;
//        int flag=0;
//        while (l < h) {
//            int m = l + (h - l) / 2;
//            if (nums[m] >= key) {
//                h = m;
//                if(nums[m]==key)
//                {
//                    flag=1;
//                }
//            } else {
//                l = m + 1;
//            }
//        }
//
//        if(flag==1)
//        {
//            for(int i=l;i<nums.length-1;i++)
//            {
//                if(nums[i]!=nums[i+1])
//                {
//                    break;
//                }
//                else{
//                    l++;
//                }
//            }
//        }else{
//            l--;
//        }
//        return l;
//    }

//    public static int binarySearch(int[] nums, int key) {
//        if(key<=0)
//        {
//            return -1;
//        }
//        int l = 0, h = nums.length - 1;
//        int flag=0;
//        while (l < h) {
//            int m = l + (h - l) / 2;
//            if (nums[m] >= key) {
//                h = m;
//                if(nums[m] == key){
//                    flag=1;
//                }
//            } else {
//                l = m + 1;
//            }
//        }
//        if(flag==1)
//        {
//             for(int i=l;i<nums.length-1;i++)
//             {
//                 if(nums[i]!=nums[i+1])
//                 {
//                     break;
//                 }
//                 else{
//                     l++;
//                 }
//             }
//        }
//        else{
////            for(int i=l;i<nums.length-1;i++)
////            {
////                if(nums[i]>key)
////                {
////                    break;
////                }
////                else{
////                    l++;
////                }
////            }
//            l--;
//        }
//
//        return l;
//    }
//    public int breakfastNumber(int[] staple, int[] drinks, int x) {
//        int cnt=0;
//        Arrays.sort(staple);
//        Arrays.sort(drinks);
//        for(int i:staple)
//        {
//            if(i>x){
//                break;
//            }
//            else{
//                int index = binarySearch2(drinks, x-i);
//
//                System.out.println(index);
//                System.out.println("x");
//                if(index<=-1){
//                    cnt+=0;
//                }else{
//                    cnt+=index+1;
//                }
//
//
//
//            }
//
//        }
//        return  cnt % 1000000007 ;
//    }



}
