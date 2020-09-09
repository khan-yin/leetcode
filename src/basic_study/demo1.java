package basic_study;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class demo1 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("apple"); // size=1
        list.add(null); // size=2
        list.add("pear"); // size=3
        String second = list.get(1); // null
        System.out.println(second);

        List<String> list2 = List.of("apple", "pear", "banana");
        for (Iterator<String> it = list2.iterator(); it.hasNext(); ) {
            String s = it.next();
            System.out.println(s);
        }

        List<String> list3 = List.of("apple", "pear", "banana");
        for (String s : list3) {
            System.out.println(s);
        }


    }
}
