package 回文排列;

public class Solution {
    public boolean canPermutePalindrome(String s) {
        int count=0;
        int[] lis=new int[256];
        for(char ch:s.toCharArray())
        {
            lis[ch]++;
            if((lis[ch]&1)==1)
            {
                count++;
            }else{
                count--;
            }
        }
        return count<=1;
        // int[] lis= new int[900];
        // char[] ss=s.toCharArray();
        // for(int i=0;i<ss.length;i++)
        // {
        //     int index=ss[i]-0;
        //     lis[index]++;
        // }
        // int one=0;
        // int two=0;
        // for(int i=0;i<400;i++)
        // {
        //     if(lis[i]==2)
        //     {
        //         two++;
        //     }
        //     else if (lis[i]==1)
        //     {
        //         one++;
        //     }
        // }
    }
}
