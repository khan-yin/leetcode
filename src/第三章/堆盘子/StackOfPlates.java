package 第三章.堆盘子;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class StackOfPlates {
    private List<Stack<Integer>> list;
    private int cap;

    public StackOfPlates(int cap) {
        list=new ArrayList<Stack<Integer>>();
        this.cap=cap;
    }

    public void push(int val) {
        if(cap<=0){
            return;
        }
        if(list.isEmpty()){
            list.add(new Stack<Integer>());
        }
        if(this.list.get(this.list.size() - 1).size() >= this.cap) {
            this.list.add(new Stack<Integer>());
        }
        list.get(this.list.size() - 1).push(val);
    }

    public int pop() {
        if(list.isEmpty()||cap<=0){
            return -1;
        }
        Stack<Integer> stack = list.get(this.list.size()-1);
        Integer pop = stack.pop();
        if(stack.isEmpty()) {
            this.list.remove(this.list.size() - 1);
        }
        return pop;
    }

    public int popAt(int index) {
        if(list.size() <= 0 || index > list.size() - 1) {
            return  -1;
        }
        Stack<Integer> stack = this.list.get(index);
        Integer pop = stack.pop();
        if(stack.isEmpty()) {
            this.list.remove(index);
        }
        return pop;
    }
}
