// PAT甲级真题1116
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 10100;

unordered_map<string,int> mp;
bool vis[N];

string price[3] = {"Mystery Award","Minion","Chocolate"};



bool is_prime(int x)
{
    if(x<2) return false;
    for(int i=2;i<=x/2;i++)
    {
        if(x % i ==0) return false;
    }
    return true;
}


string get_price(int i)
{
    if(i==1) return price[0];
    else if(is_prime(i)) return price[1];
    else return price[2];
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        mp[x]=i;
    }
    
    
    int k;
    scanf("%d", &k);
    while (k -- )
    {
        string x;
        cin>>x;
        cout<<x<<": ";
        if(!mp.count(x))
        {
            cout<<"Are you kidding?"<<endl;
            continue;
        }
        int id = mp[x];
        if(vis[id]) cout<<"Checked"<<endl;
        else
        {
            vis[id]=true;
            cout<<get_price(id)<<endl;
        }
        
        
        
    }
    return 0;
}