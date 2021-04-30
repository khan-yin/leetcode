#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;

const int N = 300010; //30w是因为add和query操作中所涉及到的下标个数为n+2m
//存储所有的原始下标，相当于将原始下标映射到alls的下标即映射空间当中，然后再用a[]数组来存储映射下标的值用于计算和更新
vector<int> alls; 
int a[N],s[N];

vector<PII> add, query; //add用来记录a[x]+=c query用来存储左右边界求区间和，查询原数组下标映射空间的位置是采用二分的方法进行

//二分查询x在alls空间当中的映射下标
inline int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid; 
        else l = mid + 1;
    }
    return r+1;//因为后续要使用前缀和，所以返回的坐标要加上1方便迭代；即映射到1,2,3....n
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    while (n -- )
    {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x,c});
        alls.push_back(x);
    }
    
    while (m -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    
    sort(alls.begin(),alls.end());//对alls里面的原始下标排序
    alls.erase(unique(alls.begin(),alls.end()),alls.end());//删除重复元素
    
    //通过上述操作以后，alls里面的元素下标是发生了变化的，所以我们需要通过二分去重新获取映射后的小区间a[]中对应x的下标
    //此时我们可以利用小区间的前缀和来求区间和
    
    for(auto item : add)// PII{x,c}
    {
        int x=find(item.first);//二分求原始下标在映射空间中对应的下标
        a[x]+=item.second; // 更新映射空间对应下标的值
    }
    
    //求出映射空间的前缀和
    for(int i=1;i<=alls.size();i++)
    {
        s[i] = s[i-1] + a[i];
    }
    
    for(auto item : query)//PII{l,r}
    {
        int l = find(item.first);
        int r = find(item.second);
        printf("%d\n",s[r] - s[l-1]); // 映射空间的和与原数组一致
    }
    
    return 0;
}