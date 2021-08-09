// PAT甲级真题1055
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;


// 输出必须按照净资产的非递增顺序排列，
// 如果净资产相同，则按照年龄不降序排列，如果年龄也相同，则按照字典序不降序排列。
struct People
{
    string name;
    int year;
    int worth;
    bool operator<(const People &p) const
    {
        if(worth != p.worth) return worth > p.worth;
        else if(year!=p.year) return year < p.year;
        else return name < p.name;
    }
}P[N];


vector<People> ages[N];
int idx[N]; //用于存储在多路归并时，每个vector的指针位置

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    char name[10];
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",name,&P[i].year,&P[i].worth);
        P[i].name = name;
        ages[P[i].year].push_back(P[i]);
    }

    //多路归并前先让序列有序
    for (auto& age: ages) sort(age.begin(), age.end());

    for(int c=1;c<=m;c++)
    {
        printf("Case #%d:\n",c);
        int k,a,b;
        scanf("%d%d%d", &k, &a,&b);
        memset(idx,0,sizeof idx);
        bool flag=false;
        for(int i=1;i<=k;i++)
        {
            int t =-1;
            for(int j = a;j<=b;j++)
            {
                // 当前vector还没有被遍历完
                if(idx[j]<ages[j].size())
                {
                    //当前存在需要排在t前面的people就更新
                    if(t==-1 || ages[j][idx[j]] < ages[t][idx[t]])
                    {
                        t = j;
                    }
                }
            }
            // 没有找到则说明已经遍历完了，直接退出循环
            if(t==-1) break;
            auto& p = ages[t][idx[t]];
            printf("%s %d %d\n",p.name.c_str(),p.year,p.worth);
            //ages[t]数组的当前排在最前面的people编号++
            idx[t]++;
            flag=true;
        }
        //如果不存在
        if(!flag) puts("None");

    }

    return 0;
}
