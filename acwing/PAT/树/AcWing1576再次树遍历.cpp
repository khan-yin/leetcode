// PAT甲级真题1086
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 40;

int l[N], r[N];

void dfs(int root,int x)
{
    if(l[root]) dfs(l[root],x);
    if(r[root]) dfs(r[root],x);
    cout<<root;
    if(root!=x) cout<<" ";
}

int main()
{
    int n;
    stack<int> stk;
    scanf("%d", &n);
    int root = 0;
    string last;
    int lastnum=0;
    for(int i=0;i<2*n;i++)
    {
        string op;
        cin>>op;
        if(op=="Push")
        {
            int x;
            cin>>x;
            if(!root) root=x;
            else
            {
                if(last=="Push") 
                    l[lastnum] = x;
                else 
                    r[lastnum] = x;
            }
            last="Push";
            lastnum = x;
            stk.push(x);
        }
        else
        {
            lastnum = stk.top();
            stk.pop();
            last="Pop";
        }
    }
    
    
    dfs(root,root);
    return 0;
}