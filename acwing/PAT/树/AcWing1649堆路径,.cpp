// PAT甲级真题1155
/*y总版本*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

int n;
int h[N];
bool gt, lt;
vector<int> path;

void dfs(int u)
{
    path.push_back(h[u]);
    if (u * 2 > n)  // 叶节点
    {
        cout << path[0];
        for (int i = 1; i < path.size(); i ++ )
        {
            cout << ' ' << path[i];
            if (path[i] > path[i - 1]) gt = true;
            else if (path[i] < path[i - 1]) lt = true;
        }
        cout << endl;
    }

    if (u * 2 + 1 <= n) dfs(u * 2 + 1);
    if (u * 2 <= n) dfs(u * 2);

    path.pop_back();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> h[i];

    dfs(1);

    if (gt && lt) puts("Not Heap");
    else if (gt) puts("Min Heap");
    else puts("Max Heap");

    return 0;
}

/*自己版本*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int tree[N];

bool ismax,ismin;

vector<vector<int>> res;

void check(int x,vector<int> path)
{
    
    int l = 2*x;
    int r = 2*x+1;
    path.push_back(tree[x]);
    
    if(l>n&&r>n)
    {
        res.push_back(path);
        return;
    }
    
    if(r<=n)
    {
        if(tree[r]<=tree[x]) ismax=true;
        if(tree[r]>=tree[x]) ismin=true;
        check(r,path);
    }
    
    if(l<=n)
    {
        if(tree[l]<=tree[x]) ismax=true;
        if(tree[l]>=tree[x]) ismin=true;
        check(l,path);
    }
}



int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d", &tree[i]);
    }
    
    vector<int> path;
    check(1,path);
    
    for(auto& p : res)
    {
        printf("%d",p[0]);
        for(int i=1;i<p.size();i++) printf(" %d",p[i]);
        printf("\n");
    }
    
    if(ismax&&ismin) puts("Not Heap");
    else if(ismax) puts("Max Heap");
    else if(ismin) puts("Min Heap");
    else puts("Not Heap");
    
    return 0;
}