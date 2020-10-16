package Scanner_study;
/**
 * A + B Problem II
 */

import java.math.BigInteger;
import java.util.Scanner;

public class hdu1002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = 1;
        while (i <= n) {
//            String s1 = sc.next();
//            String s2 = sc.next();
            BigInteger a1 = sc.nextBigInteger();
            BigInteger a2 = sc.nextBigInteger();
            System.out.println("Case " + i + ":");
//            BigInteger a1 = new BigInteger(s1);
//            BigInteger a2 = new BigInteger(s2);
            System.out.println(a1 + " + " + a2 + " = " + a1.add(a2));
            if (i != n)
                System.out.println();
            i++;
        }
    }
}
