package 第16章.单词频率;

import java.util.HashMap;

public class WordsFrequency {
    public HashMap<String, Integer> map = new HashMap<>();

    public WordsFrequency(String[] book) {

        for (String a : book) {
            // System.out.println(map.get(a));
            if (map.get(a) == null)
                map.put(a, 1);
            else {
                Integer cnt = map.get(a);
                map.put(a, ++cnt);
            }
        }
    }

    public int get(String word) {
        if (map.get(word) == null)
            return 0;
        else {
            return map.get(word);
        }
    }
}
