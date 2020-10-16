package Scanner_study;

import java.util.Scanner;

public class demo2 {
    //例：以输入"0"，结束输出
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (!sc.hasNext("0")) {
            System.out.println(sc.next());
        }
    }

}
