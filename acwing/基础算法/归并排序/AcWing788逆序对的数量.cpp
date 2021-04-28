#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100100;
int a[N],tmp[N];

long long cnt=0;
void merge_sort(int q[],int l,int r)
{
    if(l>=r)
        return;
    
    int mid = l + r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
            tmp[k++]=q[i++];
        else
        {
            cnt+=(mid-i+1);//计数
            tmp[k++]=q[j++];
        }
    }

    while(i<=mid)   tmp[k++]=q[i++];
    
    while(j<=r)     tmp[k++]=q[j++];
    
    for(i=l,j=0;i<=r;i++,j++)   q[i]=tmp[j];

}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    merge_sort(a,0,n-1);
    printf("%lld",cnt);
    return 0;
}