package 每日一题.反转字符串;

public class Solution {
    public void reverseString(char[] s) {
        int len = s.length;
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
}
