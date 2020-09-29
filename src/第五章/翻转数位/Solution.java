package 第五章.翻转数位;

public class Solution {
    public int reverseBits(int num) {
        String s = Integer.toBinaryString(num);
        String[] arr = s.split("0");
        if (arr.length < 1) {
            return arr.length + 1;
        }
        int max = arr[0].length();
        int res = max + 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1].length() + arr[i].length() > max) {
                max = arr[i - 1].length() + arr[i].length();
                res = max + 1;
            }
        }
        return res > 32 ? 32 : res;
    }
}
