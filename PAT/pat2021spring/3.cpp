#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

struct Tree
{
    int left;
    int right;
};

Tree tree[1006];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tree[i]);
    }

    string a;
    for(int i=1;i<=m;i++)
    {
        
        35 is the root
        46 and 26 are siblings
        88 is the parent of 46
        35 is the left child of 26
        35 is the right child of 46
        -1 is the root
    }
    return 0;
}