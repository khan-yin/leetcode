package 第八章.无重复字符串的排列组合;

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
        total.add(S);
        for (int i = 0; i < S.length() - 1; i++) {
            int size = total.size();
            for (int j = i + 1; j < S.length(); j++) {
                for (int k = 0; k < size; k++) {
                    String temp = swap(total.get(k), i, j);
                    total.add(temp);
                }

            }
        }
        return total.toArray(new String[total.size()]);
    }

    // ArrayList<String> total=new ArrayList<>();
    // public void dfs(Set<String> temp,String s)
    // {
    //     if(temp.isEmpty())
    //     {
    //         System.out.println(s);
    //         total.add(s);
    //         return;
    //     }

    //     for(String c:temp)
    //     {
    //         // s+=c;
    //         temp.remove(c);
    //         dfs(temp,s+c);
    //         temp.add(c);
    //     }


    // }

    // public String[] permutation(String S) {
    //     int len=S.length();
    //     char[] ch = S.toCharArray();
    //     // int[] count=new int[len];
    //     Set<String> set = new HashSet<>();
    //     for(char c :ch)
    //     {
    //         set.add(String.valueOf(c));
    //     }
    //     for(int i=0;i<len;i++)
    //     {
    //         String str=""+S[i];
    //         Set<String> temp=set;
    //         temp.remove(S[i]);
    //         dfs(temp,str);
    //     }
    //     return total.toArray(new String[total.length()]);
    // }
}
