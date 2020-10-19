package 每日一题.比较含退格的字符串;

import java.util.Stack;

public class Solution {
    public static boolean backspaceCompare(String S, String T) {
        Stack<Character> s = new Stack<>();
        Stack<Character> t = new Stack<>();
        for (char a : S.toCharArray()) {
            if (a == '#') {
                if (!s.isEmpty())
                    s.pop();
                continue;
            }
            s.push(a);
        }
        for (char b : T.toCharArray()) {
            if (b == '#') {
                if (!t.isEmpty())
                    t.pop();
                continue;
            }
            t.push(b);
        }
        if (s.size() != t.size()) {
            return false;
        }
        return s.equals(t);
    }

    public static void main(String[] args) {
        System.out.println(backspaceCompare("y#fo##f", "y#f#o##f"));
    }
}
