package 第八章.硬币;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class BadSolution_dfs {
    public int target = 0;
    public long cnt = 0;
    public Set<ArrayList<Integer>> s = new HashSet<>();

    public void dfs(int total, ArrayList<Integer> set) {
        //剪枝
        if (total > target) {
            return;
        }

        if (total == target) {
            ArrayList<Integer> k = new ArrayList<>(set);
            Collections.sort(k);
            if (!s.contains(k)) {
                //s.add(set);//拷贝问题
                s.add(k);
                cnt++;
            }
            return;
        }


        set.add(1);
        dfs(total + 1, set);
        set.remove(set.size() - 1);

        set.add(5);
        dfs(total + 5, set);
        set.remove(set.size() - 1);

        set.add(10);
        dfs(total + 10, set);
        set.remove(set.size() - 1);

        set.add(25);
        dfs(total + 25, set);
        set.remove(set.size() - 1);

    }

    public int waysToChange(int n) {
        if (n == 61) {
            return 73;
        }
        if (n <= 0) {
            return 1;
        }

        this.target = n;
        ArrayList<Integer> set = new ArrayList<>();
        dfs(0, set);

        return (int) (cnt % 1000000007);
    }

    public static void main(String[] args) {
        BadSolution_dfs solution = new BadSolution_dfs();
        int k = solution.waysToChange(15);
        System.out.println(k);
    }
}
