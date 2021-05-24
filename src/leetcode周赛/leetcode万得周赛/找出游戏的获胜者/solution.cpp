#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    bool stu[505];
    int findTheWinner(int n, int k) {
        int temp=0;
        int cnt=0;
        int i=1;
        int last=1;
        while(cnt<n)
        {
            if(!stu[i])
            {
                temp++;
            }

            if(temp%k==0&&!stu[i])
            {
                last = i;
                cout<<i<<" ";
                temp=0;
                stu[i]=true;
                cnt++;
            }
            i= (i+1)%(n+1)==0? 1: (i+1)%(n+1);
        }
        return last;
    }
};