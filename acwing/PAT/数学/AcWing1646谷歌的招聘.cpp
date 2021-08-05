// PAT甲级真题1152
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1010;
const int M = 40000;

int n,k;
bool vis[M];
int prime[M];
int cnt=0;

void init()
{
    for(int i=2;i<M;i++)
    {
        if (!vis[i])
        {
            prime[cnt++]=i;
            for(int j=2*i;j<M;j+=i)
                vis[j]=true;
        }
    }
}

bool check(int x)
{
    for(int i=0;prime[i]<=x / prime[i];i++)
    {
        if(x%prime[i]==0) return false;
    }
    return true;
}


int main()
{
    init();
    scanf("%d%d", &n, &k);
    string a;
    cin>>a;
    
    for(int i=0;i+k<=a.size();i++)
    {
        int t = stoi(a.substr(i,k));
        if(check(t))
        {
            cout<<a.substr(i,k)<<endl;
            return 0;
        }
    }
    
    puts("404");
    
    return 0;
}