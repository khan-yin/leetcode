package 第三章.栈排序;

import java.util.Stack;

public class SortedStack {
    Stack<Integer> a;
    Stack<Integer> b;

    public SortedStack() {
        a = new Stack<>();
        b = new Stack<>();
    }

    public void push(int val) {
        if (a.isEmpty()) {
            a.push(val);
            return;
        }
        int flag = 0;
        while (!a.isEmpty()) {
            int m = a.pop();
            if (m > val && flag == 0) {
                b.push(val);
                flag = 1;
            }
            b.push(m);
        }
        if (flag == 0)
            b.push(val);
        while (!b.isEmpty()) {
            int m = b.pop();
            // System.out.println(m);
            a.push(m);
        }
    }

    public void pop() {
        if (a.isEmpty()) {
            return;
        }
        a.pop();
    }

    public int peek() {
        return a.isEmpty() == true ? -1 : a.peek();
    }

    public boolean isEmpty() {
        return a.isEmpty();
    }
}
