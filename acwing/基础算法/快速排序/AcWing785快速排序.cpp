#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100010;
int a[N];


void quick_sort1(int q[],int l,int r)
{
    if(l>=r)
        return;
    
    //1.确定分界点
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    //2.调整区间
    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    //3.递归处理左右子区间
    quick_sort1(q,l,j);
    quick_sort1(q,j+1,r);
}

void quick_sort2(int q[],int l,int r)
{
    if(l>=r)
        return;
    
    //1.确定分界点
    int  x = q[l + r + 1 >> 1], i = l - 1, j = r + 1 ;
    //2.调整区间
    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    //3.递归处理左右子区间
    quick_sort2(q,l,i-1);
    quick_sort2(q,i,r);
}


//选择左右边界点会超时即quick_sort3和quick_sort4
void quick_sort3(int q[],int l,int r)
{
    if(l>=r)
        return;
    //1.确定分界点
    int x=q[l];
    int i=l-1,j=r+1;
    //2.调整区间
    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    //3.递归处理左右子区间
    quick_sort3(q,l,j);
    quick_sort3(q,j+1,r);
}


void quick_sort4(int q[],int l,int r)
{
    if(l>=r)
        return;
    //1.确定分界点
    int x=q[r];
    int i=l-1,j=r+1;
    //2.调整区间
    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    //3.递归处理左右子区间
    quick_sort4(q,l,i-1);
    quick_sort4(q,i,r);
}

int main()
{
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    quick_sort1(a,0,n-1);
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    
    return 0;
}