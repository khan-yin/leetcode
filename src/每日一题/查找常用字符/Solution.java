package 每日一题.查找常用字符;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<String> list = new ArrayList<>();

    public List<String> commonChars(String[] A) {
        if (A.length == 0)
            return list;
        int k = A[0].length();
        String less = A[0];
        for (String a : A) {
            if (k > a.length()) {
                k = a.length();
                less = a;
            }
        }
        // A[0]=A[0].replaceFirst("c","C");
        // System.out.println(A[0]);
        char[] ch = less.toCharArray();
        for (char m : ch) {
            boolean flag = true;
            for (int i = 0; i < A.length; i++) {
                // System.out.println(a);
                int index = A[i].indexOf(m);
                if (index < 0) {
                    flag = false;
                    break;
                } else {
                    A[i] = A[i].replaceFirst(String.valueOf(m), String.valueOf((32 + m)));
                    // System.out.println(a);
                }
            }
            if (flag)
                list.add(String.valueOf(m));
        }
        return list;
    }
}
