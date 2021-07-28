// PAT甲级真题1075
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include<unordered_map>

using namespace std;

const int K = 6;
const int N = 1010;
const int M = 100010;


struct User
{
    string id;
    int rk;
    int score[K]={-2,-2,-2,-2,-2,-2};
    int full;
    int total;
    bool operator<(const User &u) const
    {
        if(total==u.total)
        {
            if(full==u.full) return id<u.id;
            return full>u.full;
        }
        return total>u.total;
    }
};

int problem[K];

unordered_map<string,User> map;

int main()
{
    // 第一行包含三个整数 N,K,M，分别表示总用户数量，题目数量，以及提交数量。
    int n,k,m;
    scanf("%d%d%d", &n, &k,&m);
    
    for(int i=1;i<=k;i++) scanf("%d", &problem[i]);
    
    
    while (m -- )
    {
        // 用户编号，题目编号，以及得分
        string id;
        int proid,grade;
        cin>>id>>proid>>grade;
        auto& user = map[id];
        user.id = id;
        user.score[proid]= max(grade,user.score[proid]);
    }
    
    vector<User> res;
    for(auto& item : map)
    {
        auto& user = item.second;
        bool flag =false;
        for(int i=1;i<=k;i++)
        {
            if(user.score[i]>=0) flag=true;
            user.total += (user.score[i]>0?user.score[i]:0);
            user.full += (user.score[i]==problem[i]?1:0);
        }
        if(flag) res.push_back(user);
    }
    
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        if(!i || res[i].total!=res[i-1].total) res[i].rk = i+1;
        else res[i].rk = res[i-1].rk;
        
        printf("%d %s %d",res[i].rk,res[i].id.c_str(),res[i].total);
        for(int j=1;j<=k;j++)
        {
            if(res[i].score[j]==-2) printf(" -");
            else if(res[i].score[j]==-1) printf(" 0");
            else printf(" %d",res[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}