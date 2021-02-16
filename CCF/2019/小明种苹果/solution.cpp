#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int N,M;//苹果树的颗树和蔬果的轮数

struct AppleTree
{
    int number;
    int init;
    int subapple;
    int remain;
};

AppleTree appletree[1005];

bool cmp(AppleTree a,AppleTree b)
{
    if(a.subapple==b.subapple)
        return a.number<b.number;
    else
    {
        return a.subapple>b.subapple;
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    int sum=0;
    for(int i=1;i<=N;i++)
    {
        appletree[i].number=i;
        cin>>appletree[i].init;
        appletree[i].remain=appletree[i].init;
        for(int j=1;j<=M;j++)
        {
            int k;
            scanf("%d",&k);
            appletree[i].subapple+=(-k);
            appletree[i].remain+=k;
        }
        sum+=appletree[i].remain;
    }
    sort(appletree+1,appletree+N+1,cmp);
    cout<<sum<<" "<<appletree[1].number<<" "<<appletree[1].subapple<<endl;

    return 0;
}