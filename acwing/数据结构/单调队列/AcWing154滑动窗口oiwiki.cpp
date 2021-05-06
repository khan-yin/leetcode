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
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    int head = 0, tail = -1;
    //先将前k-1个数入队
    for (int i = 1; i < k; i++) 
    {
        while (head <= tail && a[q[tail]] >= a[i]) tail--;
        q[++tail] = i;
    }
    
    //计算第k个数入队到最后一个数入队的情况
    for(int i=k;i<=n;i++)
    {
        while(head<=tail&& a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
        while(q[head]<=i-k) head++;
        printf("%d ", a[q[head]]);
    }
    
    cout<<endl;
    head = 0, tail = -1;
    
    for (int i = 1; i < k; i++) 
    {
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;
    }
    
    for(int i=k;i<=n;i++)
    {
        while(head<=tail&& a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
        while(q[head]<=i-k) head++;
        printf("%d ", a[q[head]]);
    }
    
    return 0;
}