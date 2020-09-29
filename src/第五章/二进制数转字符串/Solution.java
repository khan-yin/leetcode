package 第五章.二进制数转字符串;

public class Solution {
    public String printBin(double num) {
        StringBuilder a = new StringBuilder();
        a.append("0.");
        while (num != 0) {
            num *= 2;
            if (num >= 1) {
                a.append(1);
                num -= 1;
            } else {
                a.append(0);
            }
            if (a.length() > 32) {
                return "ERROR";
            }
        }
        return a.toString();
    }
}
