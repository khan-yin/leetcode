#include<iostream>
#include<cstdio>
using namespace std;
int a[10004];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=a[0];
    int tempsum=0;
    int minindex=0;
    int maxindex=0;
    int tempminindex=0;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            flag=true;
        }
        tempsum+=a[i];
        if(tempsum<0)
        {
            tempsum=0;
            tempminindex=i+1;
        }
        else if(tempsum>sum){
            maxindex=i;
            minindex=tempminindex;
            sum=tempsum;
        }
    }
    if(!flag){
        sum=0;
        minindex=0;
        maxindex=n-1;
    }
    cout<<sum<<" "<<a[minindex]<<" "<<a[maxindex]<<endl;
    return 0;
}