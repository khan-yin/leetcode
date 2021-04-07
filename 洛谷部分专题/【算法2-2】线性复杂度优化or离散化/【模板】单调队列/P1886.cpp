#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n,k;
int a[1000006];
int q[1000006];//record the index of max/min value

void getmin()
{
    int head = 0, tail = 0;
    for(int i=1;i<k;i++)
    {
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        q[++tail]=i;
    }

    for(int i=k;i<=n;i++)
    {
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        q[++tail]=i;

        while(q[head]<=i-k)
            head++;
        cout<<a[q[head]]<<" ";
    }
}

void getmax()
{
    int head = 0, tail = 0;
    for(int i=1;i<k;i++)
    {
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        q[++tail]=i;
    }

    for(int i=k;i<=n;i++)
    {
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        q[++tail]=i;

        while(q[head]<=i-k)
            head++;
        cout<<a[q[head]]<<" ";
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    getmin();
    cout<<endl;
    getmax();
    cout<<endl;

    return 0;
}