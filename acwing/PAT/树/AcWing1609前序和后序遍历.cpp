// PAT甲级真题1119
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N = 40;

int pre[N],post[N];
int n;

// 返回方案数
int build(int l1,int r1,int l2,int r2,string& in)// 前序左端点,前序右端点,后序做端点,后序右端点
{
    //空树是满足的
    if(l1 > r1) return 1;
    if(pre[l1]!=post[r2]) return 0; //前后遍历的根节点不一致，构造失败
    // cout<<l1<<" "<<r1<<endl;
    int cnt = 0;
    //枚举左子树的区间右端点
    for(int k = l1;k<=r1;k++)
    {
        string lin,rin;
        int lc = build(l1+1,k,l2,l2 + k - l1 - 1,lin);
        int rc = build(k+1,r1,l2 + k - l1 - 1 + 1,r2 - 1,rin);
        // cout<<(l1==0)<<k<<" "<<endl;
        if(lc && rc)
        {
            cnt += lc*rc;
            in= lin+to_string(pre[l1])+' '+rin;
            if(cnt>1) break;
        }
    }
    // cout<<cnt<<endl;
    return cnt;
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) 
        scanf("%d", &pre[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &post[i]);
    }
    
    string in;
    
    int cnt = build(0,n-1,0,n-1,in);
    
    if(cnt>1)
    {
        puts("No");
    }
    else
    {
        puts("Yes");
    }
    
    in.pop_back();
    cout << in << endl;
    return 0;
}