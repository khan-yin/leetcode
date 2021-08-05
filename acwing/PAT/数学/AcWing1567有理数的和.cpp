// PAT甲级真题1081
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 210;

LL gcd (LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    scanf("%d", &n);

    LL a = 0, b = 1;
    LL t;
    for(int i=0;i<n;i++)
    {
        LL c,d;
        scanf("%lld/%lld", &c, &d);
        t = gcd(c, d);
        c /= t, d /= t;

        t = gcd(b, d);
        a = d/t * a + b/t * c;
        b = b/t * d;

        t = gcd(a,b);
        a/=t;
        b/=t;
    }

    if(b==1) cout<<a;
    else
    {
        if(a>=b) printf("%lld ",a/b); 
        printf("%lld/%lld",a%b,b);
    }
    return 0;
}
