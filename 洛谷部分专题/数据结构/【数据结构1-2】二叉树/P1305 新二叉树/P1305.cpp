#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//第一行为二叉树的节点数 nn。(1<=n<=26)
struct Tree
{
    int left=-1;
    int right=-1;
};

Tree nodelist[30]; 


void pre_order(int k)
{
    if(k==-1)
    {
        return;
    }
    else 
    {
        cout<<(char)(k+'a');
        pre_order(nodelist[k].left);
        pre_order(nodelist[k].right);
    }
}

int main()
{    
    int n;
    cin>>n;
    bool flag=true;
    int first=0;
    while(n--)
    {
        // getchar();
        char parent,left,right;
        cin>>parent>>left>>right;
        // scanf("%c%c%c",&parent,&left,&right);
        // cout<<parent<<" "<<left<<" "<<right<<endl;
        int p = parent - 'a';
        int l = left - 'a';
        int r = right -'a';
        if(flag)
        {
            first = p;
            flag=false;
        }
        // cout<<p<<" "<<l<<" "<<r<<endl;
        nodelist[p].left= (left=='*')? -1:l;
        nodelist[p].right= (right=='*')? -1:r;
    }
    pre_order(first);

    return 0;
}