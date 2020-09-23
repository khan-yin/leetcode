package 第16章.交换数字;

public class Solution {
    public int[] swapNumbers(int[] numbers) {

        numbers[0] = numbers[0] ^ numbers[1];//c=a^b
        numbers[1] = numbers[1] ^ numbers[0];//b=b^c=b^b^a=a
        numbers[0] = numbers[0] ^ numbers[1];//a=b^c=a^a^b=b
        return numbers;
    }
}
