#include<iostream>
#include<cstdio>
using namespace std;
int num[103];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int last=0;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        if(k>last){
            sum+=(k-last)*6;
        }
        else if(k<last){
            sum+=(last-k)*4;
        }
        last=k;
    }
    sum+=n*5;
    cout<<sum;
    return 0;
}