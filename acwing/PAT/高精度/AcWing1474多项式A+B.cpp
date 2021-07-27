// PAT甲级真题1002
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

double a[N],b[N],c[N];

void input(double a[])
{
    int n;
    cin>>n;
    while (n -- )
    {
        int i;
        double k;
        cin>>i>>k;
        a[i]=k;
    }
}

int main()
{
    input(a);
    input(b);
    int k=0;
    for(int i=0;i<N;i++)
    {
        c[i] = a[i] + b[i];
        if(c[i]) k++;
    }
    cout<<k;
    for(int i=N;i>=0;i--)
        if(c[i]) printf(" %d %.1lf",i,c[i]);
    
    return 0;
}