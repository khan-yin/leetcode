package basic_study;

import java.util.Set;
import java.util.TreeSet;

public class STL_treeset {
    public static void main(String[] args) {
        Set<String> set = new TreeSet<>();
        set.add("apple");
        set.add("banana");
        set.add("pear");
        set.add("orange");
        for (String s : set) {
            System.out.println(s);
        }



    }
}
