#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;

int a[N];

int main()
{
    int n,q,k;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    while(q--)
    {
        scanf("%d",&k);
        //起始位置是相当于是寻找第一个k的位置，而终止位置相当于是找最后一个k的位置
        int l=0,r=n-1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if(a[mid]>=k) r=mid;
            else l = mid +1;
        }
        //说明k不存在
        if(a[l]!=k)
        {
            cout<<"-1 -1"<<endl;
        }
        else
        {
            cout<<l<<" ";
            l=0,r=n-1;
            while(l<r)
            {
                int mid = l + r + 1 >> 1;
                if(a[mid]<=k) l = mid;
                else r = mid - 1;
            }
            cout<<r<<endl;
        }
    }


    return 0;
}