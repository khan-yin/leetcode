#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int a[N];

int q[N];//单调队列存储的是对应极值的下标

int main()
{
    int n,k;
    scanf("%d%d", &n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    int head = 0, tail = -1;
    //求min
    for(int i=0;i<n;i++)
    {
        while(head<=tail&&i-q[head]+1>k) head++; //head超出滑动窗口
        while(head<=tail&&a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
        if(i>=k-1) printf("%d ",a[q[head]]);
    }
    cout<<endl;
    head = 0, tail = -1;
    //求max
    for(int i=0;i<n;i++)
    {
        while(head<=tail&&i-q[head]+1>k) head++; //head超出滑动窗口
        while(head<=tail&&a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
        if(i>=k-1) printf("%d ",a[q[head]]);
    }
    
    
    return 0;
}