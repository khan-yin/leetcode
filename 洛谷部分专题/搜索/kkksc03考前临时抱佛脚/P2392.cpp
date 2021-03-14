#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int num[5];
int homework[25];
int dp[2501];
int sum;
int main()
{
    for(int i=1;i<=4;i++)
        scanf("%d",&num[i]);
    int cnt=1;
    int t=0;
    for(int i=1;i<=4;i++)
    {
        sum=0;	
		for(int j=1;j<=num[i];j++)
		{
            cin>>homework[j];//输入
			sum+=homework[j];//总时间累加
        }

        for(int j=1;j<=num[i];j++)
            for(int k=sum/2;k>=homework[j];k--)
            {
                dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);//01背包
            }
        t+=sum-dp[sum/2];//累加为另一个脑子
		for(int j=1;j<=sum/2;j++)
		    dp[j]=0;//清零
    }   

    cout<<t<<endl;
    return 0;
}