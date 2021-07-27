// PAT甲级真题1015
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

//判断一个数是否为质数
bool is_prime(int n)
{
    if (n < 2) return false; // 1和0不是质数
    for(int i=2;i*i<=n;i++)
    {
        if(n % i == 0) return false; 
    }
    return true;
}


int get(char c)
{
    if(c<='9') return c-'0';
    else return c-'a' + 10;
}


char tochar(int c)
{
    if(c<=9) return c+'0';
    else return 'a' + c - 10;
}

//一个r进制数num转10进制
int numr_to10(string num,int r)
{
    int res = 0;
    for(int i=0;i<num.size();i++)
    {
        res = res * r + get(num[i]);
    }
    return res;
}

//一个10进制数num转r进制
string num10_tor(string num,int r)
{
    string res;
    int n = numr_to10(num,10); //先转成10进制整型
    while(n)
    {
        // cout<<tochar(n % r)<<endl;
        res = tochar(n % r) + res;
        n /= r;
    }
    return res;
}



int main()
{
    int n,d;
    
    // cout<<numr_to10("6a",16)<<" "<<num10_tor("15",16)<<endl;
    
    while(cin>>n>>d && n >= 0)
    {
        
        if(!is_prime(n)) 
        {
            puts("No");
        }
        else
        {
            int res = 0;
            while(n)
            {
                res = res * d + n % d;
                n /= d;
            }
            // cout<<res<<endl;
            if(!is_prime(res)) puts("No");
            else puts("Yes");
        }
    }
    
    
    
    return 0;
}