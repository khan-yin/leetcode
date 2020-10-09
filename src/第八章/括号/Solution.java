package 第八章.括号;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int n = 0;
    public List<String> list = new ArrayList<>();

    public void dfs(String cur, int left, int right) {
        // System.out.println(cur);
        //递归出口
        if (left == n && right == n) {
            list.add(cur);
            return;
        }
        if (left < right)
            return;

        //继续递归
        //如果有剩余的左括号，添加左括号
        if (left < n)
            dfs(cur + "(", left + 1, right);
        //如果可以添加右括号，添加右括号
        if (right < n)
            dfs(cur + ")", left, right + 1);
    }

    public List<String> generateParenthesis(int n) {
        this.n = n;
        dfs("", 0, 0);
        return list;
    }
}
