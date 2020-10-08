package 第八章.无重复字符串的排列组合;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    ArrayList<String> total = new ArrayList<>();

    public void dfs(Set<String> temp, String s) {
        if (temp.isEmpty()) {
            total.add(s);
            return;
        }

        for (String c : temp) {
            // s+=c;
            temp.remove(c);
            dfs(temp, s + c);
            temp.add(c);
        }


    }

    public String[] permutation(String S) {
        int len = S.length();
        char[] ch = S.toCharArray();
        // int[] count=new int[len];
        Set<String> set = new HashSet<>();
        for (char c : ch) {
            set.add(String.valueOf(c));
        }
        for (int i = 0; i < len; i++) {
            String str = "" + S.charAt(i);
            Set<String> temp = set;
            dfs(temp, str);
        }
        return (String[]) total.toArray();
    }
}
