package basic_study;

import java.util.LinkedList;
import java.util.Queue;

public class STL_queue {
    public static void main(String[] args) {
        /**
         * 通过add()/offer()方法将元素添加到队尾；
         * 通过remove()/poll()从队首获取元素并删除；
         * 通过element()/peek()从队首获取元素但不删除。
        */
        Queue<String> q = new LinkedList<>();
        // 添加3个元素到队列:
        q.offer("apple");
        q.offer("pear");
        q.offer("banana");
        // 从队列取出元素:
//         队首永远都是apple，因为peek()不会删除它

        System.out.println(q.peek()); // apple
        System.out.println(q.poll()); // apple
        System.out.println(q.poll()); // pear
        System.out.println(q.poll()); // banana
        System.out.println(q.poll()); // null,因为队列是空的
    }
}
