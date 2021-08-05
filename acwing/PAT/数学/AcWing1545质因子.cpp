// PAT甲级真题1059
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;


LL gcd(LL a,LL b)
{
    return b ? gcd(b,a%b) : 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d=",n);
    if(n==1) printf("1");
    else
    {
        bool flag = false;
        for(int i=2;i<=n/i; i++)
        {
            int k=0;
            while(n % i == 0) 
            {
                n/=i;
                k++;
            }
            if(k==0) continue;
            if(flag) printf("*");
            else flag=true;
            printf("%d",i);
            if(k>1) printf("^%d",k);
            
        }
        if(n>1)
        {
            if(flag) printf("*");
            printf("%d",n);
        }
    }
    return 0;
}