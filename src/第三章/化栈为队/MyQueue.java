package 第三章.化栈为队;

import java.util.Stack;

public class MyQueue {
    Stack<Integer> a;
    Stack<Integer> b;

    /**
     * Initialize your data structure here.
     */
    public MyQueue() {
        a = new Stack<>();
        b = new Stack<>();
    }

    /**
     * Push element x to the back of queue.
     */
    public void push(int x) {
        a.push(x);
    }

    /**
     * Removes the element from in front of queue and returns that element.
     */
    public int pop() {
        while (!a.isEmpty()) {
            int t = a.pop();
            b.push(t);
        }
        int x = b.pop();
        System.out.println(b.isEmpty());
        while (!b.isEmpty()) {
            int t = b.pop();
            a.push(t);
        }
        System.out.println(a.isEmpty());
        return x;
    }

    /**
     * Get the front element.
     */
    public int peek() {
        while (!a.isEmpty()) {
            int t = a.pop();
            b.push(t);
        }
        int x = b.peek();
        System.out.println(b.isEmpty());
        while (!b.isEmpty()) {
            int t = b.pop();
            a.push(t);
        }
        return x;
    }

    /**
     * Returns whether the queue is empty.
     */
    public boolean empty() {
        return a.isEmpty();
    }
}
