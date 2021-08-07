// PAT甲级真题1070
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;

struct Pie
{
    double n;
    double value;
    bool operator < (const Pie& w) const
    {
        if(value * w.n != w.value * n) return value * w.n > w.value * n;
        return n > w.n;
    }
}p[N];


int main()
{
    int n;
    scanf("%d", &n);
    double m;
    scanf("%lf", &m);
    
    for(int i=0;i<n;i++) scanf("%lf", &p[i].n);
    for(int i=0;i<n;i++) scanf("%lf", &p[i].value);
    
    sort(p,p+n);
    double res = 0;
    int i=0;
    while(m>0&&i<n)
    {
        double rr = min(m,p[i].n);
        res += rr * p[i].value / p[i].n;
        m -=rr;
        i++;
    }
    
    printf("%.2lf",res);
    return 0;
}