package 第四章.幂集;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> mj = new ArrayList<>();
        List<Integer> kong = new ArrayList<>();
        mj.add(kong);
        for (int one : nums) {
            int mjsize = mj.size();
            for (int i = 0; i < mjsize; i++) {
                List<Integer> list = new ArrayList<>();
                //新增元素的方式mj.get(i).add(one);，但仍须保留原有的，则需要把原始空间提取
                list.addAll(mj.get(i));
                list.add(one);
                mj.add(list);
            }
        }
        return mj;
    }
}
