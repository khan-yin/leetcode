#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long long sum=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int w,score;
        cin>>w>>score;
        sum+=w*score;
    }
    long long res =sum>0? sum:0;
    cout<< res;
    return 0;
}