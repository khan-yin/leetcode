package 腾讯精选50题.格雷编码;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> gray = new ArrayList<Integer>();
        for (int binary = 0; binary < 1 << n; binary++) {
            gray.add(binary ^ binary >> 1);
        }
        return gray;

    }
}
