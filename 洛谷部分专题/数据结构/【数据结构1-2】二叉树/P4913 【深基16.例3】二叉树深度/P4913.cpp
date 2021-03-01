#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
    int left=0;
    int right=0;
};

Node nodelist[1000006]; 

int depth(int k)
{
    if(nodelist[k].left==0&&nodelist[k].right==0)
        return 1;
    else
    {
        int ldepth = depth(nodelist[k].left);
        int rdepth = depth(nodelist[k].right);
        return max(ldepth,rdepth)+1;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>nodelist[i].left>>nodelist[i].right;
    }
    cout<<depth(1);
    return 0;
}