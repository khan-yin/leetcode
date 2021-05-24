#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:

    int getMinSwaps(string num, int k) {
        string s=num;
        int n=num.size();
        while(k&&next_permutation(s.begin(),s.end())){
            k--;
        }
        // cout<<s<<endl;
        vector<int> c(n);//存储下标
        int cnt[10] ={ 0 }; //记录原始数组的各元素的出现次数


        //将原始元素映射到下标，然后迁移到新数组的元素的下标映射，就会出现逆序的情况，而交换的过程正是将逆序恢复成有序的过程，那么交换次数也就是逆序对的个数
        for(int i=0;i<num.size();i++)
        {
            int x = num[i] - '0';
            cnt[x]++;
            int y = cnt[x];

            for(int j=0;j<s.size();j++)
            {
                int t = s[j]-'0';
                if( t == x && --y == 0)
                {
                    c[i] = j; // 表示当前的num[i]在s中的新下标位置
                    break;
                }
            }
        }

        // 由于数量较少，直接暴力求逆序对，如果卡复杂度则用归并
        int res = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(c[i]>c[j]) res++;
        return res;
    }
};