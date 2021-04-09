#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100006];

void quick_sort(int l,int r)
{
    int mid=a[(l+r)>>1];
    int i=l,j=r;
    do
    {
        /* code */
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    } while (i<=j);

    if(l<j) quick_sort(l,j);
    if(r>i) quick_sort(i,r);
    
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(1,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}