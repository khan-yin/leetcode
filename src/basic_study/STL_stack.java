package basic_study;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class STL_stack {
    public static void main(String[] args) {
        //在Java中，我们用Deque可以实现Stack的功能
        /**
         * 把元素压栈：push(E)/addFirst(E)；
         * 把栈顶的元素“弹出”：pop(E)/removeFirst()；
         * 取栈顶元素但不弹出：peek(E)/peekFirst()。
         */
        Stack<Integer> lis =new Stack<>();
        lis.push(2);
        lis.push(4);
        System.out.println(lis.peek());
        lis.pop();
        System.out.println(lis.peek());


    }
}
