#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3100000;

int a[N];

int son[N][2],idx;

void insert(int x)
{
    int p=0;
    for (int i = 30; i>=0; i -- )
    {
        int value= x >> i & 1; // 求出x的二进制表示中第i位是几
        if(!son[p][value]) son[p][value]= ++idx;
        p = son[p][value];
    }
}

int query(int x)
{
    int p=0;
    int res = 0;
    for (int i = 30; i>=0; i -- )
    {
        int value = x>>i&1;
        // 尽量往相反的位走
        if(son[p][!value])
        {
            res += 1 << i; // res = res * 2 + value 也可以
            p = son[p][!value];
        }
        else
            //如果不存在相反的位则往相同的位走，此时该位^结果为0无需计算
            p = son[p][value];
    }
    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        res = max(res,query(a[i]));
    }
    cout<<res<<endl;
    return 0;
}
