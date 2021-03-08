#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool stu[105];

int main()
{
    int n,m;
    cin>>n>>m;
    int temp=0;
    int cnt=0;
    int i=1;
    while(cnt<n)
    {
        if(!stu[i])
        {
            temp++;
        }

        if(temp%m==0&&!stu[i])
        {
            cout<<i<<" ";
            temp=0;
            stu[i]=true;
            cnt++;
        }
        i= (i+1)%(n+1)==0? 1: (i+1)%(n+1);
    }

    return 0;
}