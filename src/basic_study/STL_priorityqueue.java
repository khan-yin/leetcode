package basic_study;

import javax.sound.midi.Soundbank;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class STL_priorityqueue {
    public static void main(String[] args) {
        Queue<String> q0 = new PriorityQueue<>();
        // 添加3个元素到队列:
        q0.offer("apple");
        q0.offer("pear");
        q0.offer("banana");

        System.out.println(q0.isEmpty());
        System.out.println(q0.poll()); // apple
        System.out.println(q0.poll()); // banana
        System.out.println(q0.poll()); // pear
        System.out.println(q0.poll()); // null,因为队列为空

        Queue<User> q = new PriorityQueue<>(new UserComparator());
        // 添加3个元素到队列:
        q.offer(new User("Bob", "A1"));
        q.offer(new User("Alice", "A2"));
        q.offer(new User("Boss", "V1"));
        System.out.println(q.poll()); // Boss/V1
        System.out.println(q.poll()); // Bob/A1
        System.out.println(q.poll()); // Alice/A2
        System.out.println(q.poll()); // null,因为队列为空
    }
}

class UserComparator implements Comparator<User> {
    public int compare(User u1, User u2) {
        if (u1.number.charAt(0) == u2.number.charAt(0)) {
            // 如果两人的号都是A开头或者都是V开头,比较号的大小:
            return u1.number.compareTo(u2.number);
        }
        if (u1.number.charAt(0) == 'V') {
            // u1的号码是V开头,优先级高:
            return -1;
        } else {
            return 1;
        }
    }
}

class User {
    public final String name;
    public final String number;

    public User(String name, String number) {
        this.name = name;
        this.number = number;
    }

    public String toString() {
        return name + "/" + number;
    }
}