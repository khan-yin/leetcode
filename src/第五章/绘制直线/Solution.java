package 第五章.绘制直线;

public class Solution {
    public int[] drawLine(int length, int w, int x1, int x2, int y) {
        int[] ans = new int[length];
        int low = (y * w + x1) / 32;
        int high = (y * w + x2) / 32;
        for (int i = low; i <= high; i++) {
            ans[i] = -1;
        }
        ans[low] = ans[low] >>> x1 % 32;
        System.out.println(ans[low]);
        ans[high] = ans[high] & Integer.MIN_VALUE >> x2 % 32;
        System.out.println(ans[high]);
        return ans;
    }
}
