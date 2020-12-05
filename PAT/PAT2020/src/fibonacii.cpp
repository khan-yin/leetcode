#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a[100000005];

int main()
{
    int k;
    cin>>k;
    a[0]=0;
    a[1]=1;
    int i=1;
    while(a[i]<k)
    {
        i++;
        a[i]=a[i-1]+a[i-2];
    }

    int big=a[i]-k;
    int small=k-a[i-1];
    cout<<(small<=big?a[i-1]:a[i]);
    
    return 0;
}