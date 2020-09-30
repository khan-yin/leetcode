package 第五章.整数转换;

public class Solution {
    public int convertInteger(int A, int B) {
        int k = 0;
        int c = A ^ B;
        String s3 = Integer.toBinaryString(c);
        char[] ch = s3.toCharArray();
        for (char cm : ch) {
            if (cm == '1') {
                k++;
            }
        }
        return k;
    }

    public int convertInteger2(int A, int B) {
        int k = 0;
        int c = A ^ B;
        while (c != 0) {
            k++;
            c &= (c - 1);
        }
        return k;
    }

}
