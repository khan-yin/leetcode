#include<iostream>
#include<algorithm>
using namespace std;

int a[10006];
int b[10006];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i =1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(i==1)
            cout<<b[i];
        else 
            cout<<" "<<b[i];
    }
    return 0;
}