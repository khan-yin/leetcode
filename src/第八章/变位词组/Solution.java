package 第八章.变位词组;

import java.util.*;

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for (String a : strs) {
            char[] t = a.toCharArray();
            Arrays.sort(t);
            String str = String.valueOf(t);
            if (!map.containsKey(str)) {
                List<String> lis = new ArrayList<String>();
                lis.add(a);
                map.put(str, lis);
            } else {
                List<String> lis = map.get(str);
                lis.add(a);
            }
        }
        res.addAll(map.values());
        return res;
    }
}
