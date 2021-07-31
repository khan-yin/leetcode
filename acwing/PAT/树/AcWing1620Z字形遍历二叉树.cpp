// PAT甲级真题1127
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 40;

int n;
int in[N], post[N];
unordered_map<int,int> l , r, pos;
int q[N];


// int build(int il, int ir, int pl, int pr)
// {
//     int root = post[pr];
//     int k = pos[root];

//     if (il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
//     if (k < ir) r[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1);

//     return root;
// }

int build(int il,int ir,int pl,int pr)
{
    int root = post[pr]; // 找到后序遍历的根节点在中序当中的对应下标
    int k = pos[root];
    if(il<k) l[root] = build(il,k-1,pl,pl + k - il-1);
    if(k<ir) r[root] = build(k+1,ir,pl+k-il,pr-1);
    
    return root;
}


void bfs(int root)
{
    int hh = 0, tt = 0;
    q[0] = root;
    int depth=0;
    while(hh<=tt)
    {
        int head = hh;
        int tail = tt;
        while(hh<=tail)
        {
            int t = q[hh++];
            if(l.count(t))q[++tt] = l[t];
            if(r.count(t))q[++tt] = r[t];
        }
        if(depth%2==0) reverse(q+head,q+tail+1);
        depth++;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> in[i];
        pos[in[i]] = i;
    }
    for (int i = 0; i < n; i ++ ) cin >> post[i];

    int root = build(0, n - 1, 0, n - 1);

    bfs(root);

    cout << q[0];
    for (int i = 1; i < n; i ++ ) cout << ' ' << q[i];
    cout << endl;

    return 0;
}