// PAT甲级真题1078
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 100100;
int msize,n;
int tsize;

int h[N];

bool is_prime(int x)  // 判定质数
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int getminsize(int s)
{
    while(!is_prime(s)) s++;
    return s;
}

int cnt=0;

int find(int x)
{
    int t = x % tsize;
    
    for(int i=0;i<tsize;i++)
    {
        int k = (t + i*i) % tsize;
        if(!h[k]) return k;
    }
    return -1;
}

int main()
{
    scanf("%d%d", &msize, &n);
    tsize = getminsize(msize);
    
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        
        int t = find(x);
        
        if(t==-1) printf("-");
        else
        {
            h[t] = x;
            printf("%d",t);
        }
        if(i!=n-1) printf(" ");
    }
    
    
    return 0;
}