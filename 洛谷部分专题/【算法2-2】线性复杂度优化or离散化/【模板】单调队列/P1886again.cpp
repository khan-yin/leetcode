#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
int a[1000006];
int q[1000006];//record index of target value

void getmin()
{
    int head=0,tail=0;
    for(int i=0;i<k-1;i++)
    {
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        q[++tail]=i;
    }
    

    for(int i=k-1;i<n;i++)
    {
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        q[++tail]=i;

        while(q[head]<=i-k)// target index is out of window
            head++;
        cout<<a[q[head]]<<" ";
    }
}

void getmax()
{
    int head=0,tail=0;
    for(int i=0;i<k-1;i++)
    {
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        q[++tail]=i;
    }

    for(int i=k-1;i<n;i++)
    {
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        q[++tail]=i;

        while(q[head]<=i-k)// target index is out of window
            head++;
        cout<<a[q[head]]<<" ";
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    getmin();
    cout<<endl;
    getmax();
    cout<<endl;
    return 0;
}