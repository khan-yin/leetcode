package Scanner_study;
/**
 * A+B for Input-Output Practice (II)
 */

import java.util.Scanner;

public class hdu1090 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(a + b);
            n--;
        }
    }
}
