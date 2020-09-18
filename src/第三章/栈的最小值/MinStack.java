package 第三章.栈的最小值;

import java.util.Stack;

public class MinStack {
    private Stack<Integer> stack;

    private Stack<Integer> minstack;

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
        minstack = new Stack<Integer>();
    }

    public void push(int x) {
        stack.push(x);
        if(minstack.size() <= 0) {
            minstack.push(x);
        }else {
            if(minstack.peek() < x) {
                minstack.push(minstack.peek());
            }else {
                minstack.push(x);
            }
        }
    }

    public void pop() {
        stack.pop();
        minstack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minstack.peek();
    }
}
