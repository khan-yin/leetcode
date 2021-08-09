// PAT甲级真题1029
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200010;

int a[N],b[N];
int c[N * 2];


int main()
{
    int n,m;
    scanf("%d", &n);
    vector<int> res;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    
    scanf("%d", &m);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    
    int mid = m + n - 1 >> 1;
    int cnt = 0;
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]<=b[j]) 
        {
            c[cnt++]=a[i++];
        }
        else
        {
            c[cnt++]=b[j++];
        } 
    }
    
    while(i<n) c[cnt++]=a[i++];
    while(j<n) c[cnt++]=b[j++];
    
    printf("%d\n", c[mid]);
    
    
    return 0;
}