package 每日一题.上升下降字符串;

public class Solution {
    public String sortString(String s) {
        int[] charmap = new int[26];
        int len = s.length();
        if (len == 0 || len == 1)
            return s;
        for (int i = 0; i < len; i++) {
            charmap[s.charAt(i) - 'a']++;
        }

        char[] newstr = new char[len];
        //也可以用StringBuffer ret = new StringBuffer();
        int cnt = 0;
        while (cnt < len) {
            for (int i = 0; i < 26; i++) {
                if (charmap[i] > 0) {
                    newstr[cnt++] = (char) ('a' + i);
                    charmap[i]--;
                }
            }

            for (int i = 25; i >= 0; i--) {
                if (charmap[i] > 0) {
                    newstr[cnt++] = (char) ('a' + i);
                    charmap[i]--;
                }
            }
        }
        return new String(newstr);
    }
}
