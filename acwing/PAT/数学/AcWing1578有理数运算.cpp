// PAT甲级真题1088
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)  // 欧几里得算法
{
    return b ? gcd(b, a % b) : a;
}


void print(LL a,LL b)
{
    if(a==0) cout<<"0";
    else if(b==0) cout<<"Inf";
    else
    {
        bool flag=false;
        if(a<0 || b<0) cout<<'(', flag=true;
        if(abs(a)>=abs(b)) 
        {
            printf("%lld",a/b);
            a= abs(a) % abs(b);
            if(a!=0) printf(" %lld/%lld", abs(a),abs(b));
        }
        else
        {
            if(flag) cout<<'-';
            printf("%lld/%lld", abs(a),abs(b));
        }
        if(flag) cout<<')';
    }
}

LL add(LL a,LL b,LL c,LL d)
{
    print(a,b);
    cout<<" + ";
    print(c,d);
    
    LL t =gcd(b,d);
    a = d/t * a + b/t * c;
    b = b/t * d;
    t = gcd(a,b);
    a /=t;
    b /=t;
    
    cout<<" = ";
    print(a,b);
}

LL sub(LL a,LL b,LL c,LL d)
{
    print(a,b);
    cout<<" - ";
    print(c,d);
    
    LL t =gcd(b,d);
    a = d/t * a - b/t * c;
    b = b/t * d;
    t = gcd(a,b);
    a /=t;
    b /=t;
    
    cout<<" = ";
    print(a,b);
}

LL mul(LL a,LL b,LL c,LL d)
{
    print(a,b);
    cout<<" * ";
    print(c,d);
    a = a * c;
    b = b * d;
    LL t = gcd(a,b);
    a /=t;
    b /=t;
    cout<<" = ";
    print(a,b);
}

LL divide(LL a,LL b,LL c,LL d)
{
    print(a,b);
    cout<<" / ";
    print(c,d);
    a = a * d;
    b = b * c;
    LL t = gcd(a,b);
    a /=t;
    b /=t;
    cout<<" = ";
    print(a,b);
}

int main()
{
    LL a,b,c,d;
    scanf("%lld/%lld %lld/%lld", &a,&b,&c,&d);
    LL t = gcd(a,b);
    a /=t;
    b /=t;
    t = gcd(c,d);
    c /=t;
    d /=t;
    add(a,b,c,d);
    cout<<endl;
    sub(a,b,c,d);
    cout<<endl;
    mul(a,b,c,d);
    cout<<endl;
    divide(a,b,c,d);
    return 0;
}