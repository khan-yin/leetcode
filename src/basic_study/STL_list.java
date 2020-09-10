package basic_study;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class STL_list {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("apple"); // size=1
        list.add(null); // size=2
        list.add("pear"); // size=3
        String second = list.get(1); // null
        System.out.println(second);

        List<String> list2 = List.of("apple", "pear", "banana");
        //它返回的是一个只读List

        //list->array
        String[] sarray = list.toArray(new String[list2.size()]);
        System.out.println(sarray);

        System.out.println("get方法");
        for (int i=0; i<list2.size(); i++) {
            String s = list2.get(i);//get方法
            System.out.println(s);
        }

        System.out.println("for_each");
        //一般用迭代器,for each也是迭代器
        for (String s : list2) {
            System.out.println(s);
        }

        System.out.println("iterator");
        for (Iterator<String> it = list2.iterator(); it.hasNext(); ) {
            String s = it.next();
            System.out.println(s);
        }



    }
}
