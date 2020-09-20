package 第三章.三合一;

public class TripleInOne {
    private int[] arr;
    private int[] stackTop; // 每个栈当前可push的索引（对应到arr中的索引）
    private int stackSize;

    public TripleInOne(int stackSize) {
        this.stackSize = stackSize;
        arr = new int[stackSize * 3];
        stackTop = new int[]{0, 1, 2};
    }

    public void push(int stackNum, int value) {
        int curStackTop = stackTop[stackNum];//得到当前下标对应的栈的栈顶下标
        if (curStackTop / 3 == stackSize) {//当当前下标是3的倍数，说明已经塞满了
            // 栈已满
            return;
        }
        arr[curStackTop] = value;//将这个元素加入当前栈的栈顶
        stackTop[stackNum] += 3;//栈顶下标+3
    }

    public int pop(int stackNum) {
        if (isEmpty(stackNum)) {//当栈为空时，返回-1
            return -1;
        }
        int value = arr[stackTop[stackNum] - 3];//删除对应的栈顶元素,前面加入元素的时候加了3，现在要减掉
        stackTop[stackNum] -= 3;//栈顶下标减小3
        return value;
    }

    public int peek(int stackNum) {
        if (isEmpty(stackNum)) {
            return -1;
        }
        return arr[stackTop[stackNum] - 3];
    }

    public boolean isEmpty(int stackNum) {
        return stackTop[stackNum] < 3;//当栈顶下标小于3，说明没有元素了
    }
}
