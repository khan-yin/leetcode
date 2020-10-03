package 第五章.下一个数;

import javax.sound.midi.Soundbank;

public class Solution {
    public static void main(String[] args) {
        findClosedNumbers(1837591841);
    }

    public static int[] findClosedNumbers(int num) {
        int[] a = {-1, -1};
//        System.out.println(1837591841&1);
        System.out.println(Integer.toBinaryString(1837591841));
        String ak = Integer.toBinaryString(num);
//        char[] p=ak.toCharArray();
        int m = ak.lastIndexOf("01");
        int n = ak.lastIndexOf("10");
        if (m < 0) {
            return a;
        } else {
            System.out.println(m);
            System.out.println(n);


        }
//        System.out.println(m);
        // if((num&1)==0){

        //     a[1]=num>>1;
        // }
        // int k=num<<1;
        // if(k>num){
        //     a[0]=k;
        // }
        return a;
    }
}
