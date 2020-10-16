package Scanner_study;
/**
 * Max Sum
 */

import java.util.Scanner;

public class hdu1003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int S = 1;//输出需要；
        while (n > 0) {

            int k = sc.nextInt();
            int[] sum = new int[k + 1];
            for (int i = 0; i < k; i++) {
                sum[i] = sc.nextInt();
            }
            int[] Text = new int[]{-10001, 1, 1};//范围在-1000到1000中；

            int Max = 0, next = 1;
            //Max中暂时存放当前最大的和;
            //next中存放序列的截至位置

            for (int i = 0; i < k; i++) {
                Max += sum[i];
                if (Max > Text[0]) {
                    Text[0] = Max; //Text[0]中存放最大的和；
                    Text[1] = next;//Text[1]存放产生最大数的序列的起始位置
                    Text[2] = i + 1;//Text[2]存放产生最大数的序列的终止位置
                }
                if (Max < 0) {//如果前面的数之和为负数，则改变起始位置，Max置零；
                    next = i + 2;
                    Max = 0;
                }
            }

            System.out.printf("Case %d:%n", S++);
            System.out.println(Text[0] + " " + Text[1] + " " + Text[2]);
            n--;
            if (n != 0) System.out.println();
        }
    }
}
