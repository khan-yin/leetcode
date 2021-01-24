package 腾讯精选50题.买卖股票的最佳时机II;

public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) return 0;
        int sum = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                sum += (prices[i] - prices[i - 1]);
        }
        return sum;
    }
}
