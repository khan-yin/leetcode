package basic_study;

import java.util.HashMap;
import java.util.Map;

public class STL_hashmap {
    public static void main(String[] args) {
        var s2 = new Student("Xiao Ming", 99);
        Student s = new Student("Xiao Ming", 99);
        Map<String, Student> map = new HashMap<>();
        map.put("Xiao Ming", s); // 将"Xiao Ming"和Student实例映射并关联
        Student target = map.get("Xiao Ming"); // 通过key查找并返回映射的Student实例
        System.out.println(target == s); // true，同一个实例
        System.out.println(map.get("Xiao Ming"));
        System.out.println(target.score); // 99
        Student another = map.get("Bob"); // 通过另一个key查找
        System.out.println(another); // 未找到返回null
        //遍历key
        Map<String, Integer> map2 = new HashMap<>();
        map2.put("apple", 123);
        map2.put("pear", 456);
        map2.put("banana", 789);
        for (String key : map2.keySet()) {
            System.out.println(map2.get(key));
            Integer value = map2.get(key);
            System.out.println(key + " = " + value);
        }



        //遍历entry
        Map<String, Integer> map3 = new HashMap<>();
        map3.put("apple", 123);
        map3.put("pear", 456);
        map3.put("banana", 789);
        for (Map.Entry<String, Integer> entry : map3.entrySet()) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            System.out.println(key + " = " + value);
        }

    }
}

//class Student {
//    public String name;
//    public int score;
//    public Student(String name, int score) {
//        this.name = name;
//        this.score = score;
//    }
//}
