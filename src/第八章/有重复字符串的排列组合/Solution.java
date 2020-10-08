package 第八章.有重复字符串的排列组合;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution {
    //交换位置
    private String swap(String s, int pos1, int pos2) {
        char[] chars = s.toCharArray();
        char sa = chars[pos1];
        chars[pos1] = chars[pos2];
        chars[pos2] = sa;
        return new String(chars);
    }

    public String[] permutation(String S) {
        List<String> total = new ArrayList<>();
        Set<String> set = new HashSet<>();
        total.add(S);
        set.add(S);
        for (int i = 0; i < S.length() - 1; i++) {
            int size = total.size();
            for (int j = i + 1; j < S.length(); j++) {
                for (int k = 0; k < size; k++) {
                    String temp = swap(total.get(k), i, j);
                    total.add(temp);
                    set.add(temp);
                }

            }
        }
        return set.toArray(new String[set.size()]);
    }
}
