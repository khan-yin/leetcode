// PAT甲级真题1130
/*我的代码*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N = 40;

int l[N],r[N];
bool has_father[N];
string e[N];

int n;

string dfs(int x)
{
    string res = e[x];
    string left,rigth;
    if(l[x]>0) left = dfs(l[x]);
    if(r[x]>0) rigth = dfs(r[x]);
    res = left + res + rigth;
    if(left.size()>0 || rigth.size()>0) 
    {
        res ='(' + res + ')';
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++)
    {
        string data;
        int left,right;
        cin>>data>>left>>right;
        e[i]=data;
        l[i]=left;
        r[i]=right;
        has_father[left]=true;
        has_father[right]=true;
    }
    
    int root =1;
    while(root<=n&&has_father[root]) root++;
    
    string r =dfs(root);
    if(r.size()<3) cout<<r<<endl;
    else cout<<r.substr(1,r.size()-2)<<endl;
    return 0;
}
/*y总版本*/
#include <iostream>

using namespace std;

const int N = 25;

int n;
int l[N], r[N];
string w[N];
bool st[N], is_leaf[N];

string dfs(int u)
{
    string left, right;
    if (l[u] != -1)
    {
        left = dfs(l[u]);
        if (!is_leaf[l[u]]) left = "(" + left + ")";
    }
    if (r[u] != -1)
    {
        right = dfs(r[u]);
        if (!is_leaf[r[u]]) right = "(" + right + ")";
    }

    return left + w[u] + right;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i] >> l[i] >> r[i];
        if (l[i]) st[l[i]] = true;
        if (r[i]) st[r[i]] = true;

        if (l[i] == -1 && r[i] == -1) is_leaf[i] = true;
    }

    int root = 1;
    while (st[root]) root ++ ;

    cout << dfs(root) << endl;

    return 0;
}
