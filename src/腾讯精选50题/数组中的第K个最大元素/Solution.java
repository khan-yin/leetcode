package 腾讯精选50题.数组中的第K个最大元素;

import java.util.PriorityQueue;

public class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int num : nums) {
            heap.add(num);
            if (heap.size() > k)
                heap.poll();
        }
        return heap.peek();
    }
}
