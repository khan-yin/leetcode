#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#define ll long long
using namespace std;

bool is7(int x)
{
    if(x % 7==0&&x!=0)
        return true;
    else
    {
        while(x>0)
        {
            int a = x%10;
            if(a==7)
                return true;
            x/=10;
            
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a=1,b=2,c=3,d=4;
    int cnt=4;
    int ca=0,cb=0,cc=0,cd=0;
    while(cnt<n)
    {
        a+=4;
        if(is7(a))
            ca++;
        else
        {
            cnt++;
            if(cnt==n)
                break;
        }
        b+=4;
        if(is7(b))
            cb++;
        else
        {
            cnt++;
            if(cnt==n)
                break;
        }
        c+=4;
        if(is7(c))
            cc++;
        else
        {
            cnt++;
            if(cnt==n)
                break;
        }
        d+=4;
        if(is7(d))
            cd++;
        else
        {
            cnt++;
            if(cnt==n)
                break;
        }
    }
    cout<<ca<<endl;
    cout<<cb<<endl;
    cout<<cc<<endl;
    cout<<cd<<endl;
    return 0;
}