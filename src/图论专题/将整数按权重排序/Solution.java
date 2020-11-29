package 图论专题.将整数按权重排序;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Solution {
    public int count(int x)
    {   //位运算判断奇数偶数
        int c=0;
        while(x!=1)
        {
            if((x&1)==0)//偶数
                x/=2;
            else
                x=3*x+1;
            c++;
        }
        return c;
    }
    public int getKth(int lo, int hi, int k) {
        List<NumCnt> arr = new ArrayList<>();
        for(int num=lo;num<=hi;num++)
        {
            arr.add(new NumCnt(num,count(num)));
        }
        //自定义排序
        Collections.sort(arr, new Comparator<NumCnt>() {
            @Override
            public int compare(NumCnt o1, NumCnt o2) {
                return o1.compareTo(o2);
            }
        });
        // Collections.sort(arr);
        return arr.get(k-1).number;
    }
}

class NumCnt
{
    public int number;
    public int cnt;
    public NumCnt(int number,int cnt){
        this.number=number;
        this.cnt=cnt;
    }
    // @Override
    public int compareTo(NumCnt other) {
        if(cnt==other.cnt)
        {
            return number<other.number?-1:1;
        }
        else
            return cnt<other.cnt?-1:1;
    }
}
