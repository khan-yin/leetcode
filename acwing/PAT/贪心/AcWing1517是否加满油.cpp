// PAT甲级真题1033
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 510;

int cmax,d,davg,n;

struct Station
{
    double p;
    double dis;
    bool operator < (const Station& s) const
    {
        return dis < s.dis;
    }
}s[N];

int main()
{
    // Cmax，油箱的最大容量，D，杭州到目的地城市的距离，Davg，每单位汽油可供汽车行驶距离，N，加油站总数。
    cin>>cmax>>d>>davg>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf", &s[i].p, &s[i].dis);
    }
    s[n] = {0, (double)d};
    
    sort(s,s+n+1);
    
    if(s[0].dis!=0)
    {
        puts("The maximum travel distance = 0.00");
        return 0;
    }
    double oil = 0;
    double res = 0;
    
    for(int i=0;i<n;)
    {
        int t = -1;
        for(int j=i+1;j<=n&&s[j].dis - s[i].dis <= cmax * davg;j++)
        {
            if (s[j].p < s[i].p)
            {
                t = j;
                break;
            }
            else if (t == -1 || s[j].p < s[t].p)
                t = j;
        }
        
        if (t == -1)
        {
            printf("The maximum travel distance = %.2lf\n", s[i].dis + (double)cmax * davg);
            return 0;
        }
        
        if(s[t].p <=s[i].p)
        {
            res += ((s[t].dis - s[i].dis) / davg - oil) * s[i].p;
            i = t;
            oil = 0;
        }
        else
        {
            res += s[i].p * (cmax-oil);
            oil = cmax - (s[t].dis - s[i].dis) / davg;
            i = t;
        }
    }
    
    printf("%.2lf\n", res);
    
    
    return 0;
}