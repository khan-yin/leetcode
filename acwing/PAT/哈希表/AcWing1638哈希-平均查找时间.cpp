// PAT甲级真题1145
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

int find(int x,int&cnt)
{
    int t = x % tsize;
    cnt=1;
    for(int i=0;i<tsize;i++,cnt++)
    {
        int k = (t + i*i) % tsize;
        if(!h[k] || h[k]==x) return k;
    }
    return -1;
}

int main()
{
    int m;
    scanf("%d%d", &msize, &n);
    scanf("%d", &m);
    tsize = getminsize(msize);

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int c=0;
        int t = find(x,c);
        if(t==-1) printf("%d cannot be inserted.\n",x);
        else h[t] = x;
    }



    int times = 0;
    for (int i = 0; i < m; i ++ )
    {
        int x, count;
        cin >> x;
        find(x, count);
        times += count;
    }


    printf("%.1lf\n",(double)times/m);

    return 0;
}