package basic_study;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;

public class Bigdigit {
    public static void main(String[] args) {
        BigInteger bi = new BigInteger("1234567890");
        System.out.println(bi.pow(5)); // 2867971860299718107233761438093672048294900000

        BigInteger i1 = new BigInteger("1234567890");
        BigInteger i2 = new BigInteger("12345678901234567890");
        BigInteger sum = i1.add(i2); // 12345678902469135780

        BigDecimal bd = new BigDecimal("123.4567");
        System.out.println(bd.multiply(bd)); // 15241.55677489

        BigDecimal d1 = new BigDecimal("123.45");
        BigDecimal d2 = new BigDecimal("123.4500");
        BigDecimal d3 = new BigDecimal("1234500");
        //用scale()表示小数位数
        System.out.println(d1.scale()); // 2,两位小数
        System.out.println(d2.scale()); // 4
        System.out.println(d3.scale()); // 0

        BigDecimal d11 = new BigDecimal("123.456789");
        BigDecimal d22 = d11.setScale(4, RoundingMode.HALF_UP); // 四舍五入，123.4568
        BigDecimal d33 = d11.setScale(4, RoundingMode.DOWN); // 直接截断，123.4567
        System.out.println(d22);
        System.out.println(d33);


        BigDecimal d1x = new BigDecimal("123.456");
        BigDecimal d2x = new BigDecimal("23.456789");
        BigDecimal d3x = d1x.divide(d2x, 10, RoundingMode.HALF_UP); // 保留10位小数并四舍五入

        BigDecimal n = new BigDecimal("12.345");
        BigDecimal m = new BigDecimal("0.12");
        BigDecimal[] dr = n.divideAndRemainder(m);
        System.out.println(dr[0]); // 102
        System.out.println(dr[1]); // 0.105

        BigDecimal nn = new BigDecimal("12.75");
        BigDecimal mm = new BigDecimal("0.15");
        BigDecimal[] drr = nn.divideAndRemainder(mm);
        if (drr[1].signum() == 0) {
            // n是m的整数倍
            System.out.println("n是m的整数倍");
        }
    }
}
