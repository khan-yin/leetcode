package basic_study;

public class 包装类型 {
    public static void main(String[] args) {
        int i=100;
        Integer n1=Integer.valueOf(i);
        Integer a=100;
        System.out.println(n1);
        System.out.println(a);
        int x=n1.intValue();
        System.out.println(x);

        int x1 = Integer.parseInt("100"); // 100
        int x2 = Integer.parseInt("100", 16); // 256,因为按16进制解析
        //比较两个Integer类型
        System.out.println(n1.equals(a));

        System.out.println(Integer.toString(100)); // "100",表示为10进制
        System.out.println(Integer.toString(100, 36)); // "2s",表示为36进制
        System.out.println(Integer.toHexString(100)); // "64",表示为16进制
        System.out.println(Integer.toOctalString(100)); // "144",表示为8进制
        System.out.println(Integer.toBinaryString(100)); // "1100100",表示为2进制
    }
}
