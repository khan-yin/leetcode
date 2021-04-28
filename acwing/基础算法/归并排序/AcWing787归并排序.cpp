#include<iostream>
#include<cstdio>
using namespace std;

const int N=100010;

int a[N],tmp[N];

void merge_sort(int q[],int l,int r)
{
    if(l>=r)
        return;
    //确定分界点
    int mid = l + r >> 1;
    
    //递归处理子序列
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    //合并有序序列
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(q[i]<=q[j])// 取等号，保证归并排序的稳定性
            tmp[k++]=q[i++];
        else
            tmp[k++]=q[j++];
    }

    while(i<=mid) 
        tmp[k++]=q[i++];
    while(j<=r) 
        tmp[k++]=q[j++];

    for(i=l,j=0;i<=r;i++,j++)
        q[i]=tmp[j];

}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}