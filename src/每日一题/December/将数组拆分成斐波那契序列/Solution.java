package 每日一题.December.将数组拆分成斐波那契序列;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public String S;
    public int length = 0;

    public boolean dfs(List<Integer> list, int curIndex, int sum, int preNum) {                //curIndex指i,sum表示F[i-1] + F[i-2] preNum是指F[i-1]
        //递归出口
        if (curIndex >= length) {
            return list.size() >= 3;
        }
        long tempNum = 0;
        for (int i = curIndex; i < length; i++) {
            if (i > curIndex && S.charAt(curIndex) == '0')//以0开头的只能为0,不能继续凑，剪枝
                break;
            tempNum = tempNum * 10 + S.charAt(i) - '0';
            if (tempNum > Integer.MAX_VALUE)//超过int，剪枝
                break;
            int curNum = (int) tempNum;
            if (list.size() >= 2)//从第三个数开始需要监测是否满足每一项F[i-1] + F[i-2] = F[i]
            {
                if (curNum < sum) { //可以继续增大curNum
                    continue;
                } else if (curNum > sum) {//已经大于前两个数的和就可以直接剪枝
                    break;
                }
            }
            //只有等于才满足要求，继续进行迭代
            list.add(curNum);
            //继续递归
            if (!dfs(list, i + 1, preNum + curNum, curNum)) {   //找不到则回退
                list.remove(list.size() - 1);
            } else
                return true;
        }
        return false;
    }

    public List<Integer> splitIntoFibonacci(String S) {
        this.S = S;
        this.length = S.length();
        List<Integer> list = new ArrayList<>();
        dfs(list, 0, 0, 0);
        return list;
    }
}
