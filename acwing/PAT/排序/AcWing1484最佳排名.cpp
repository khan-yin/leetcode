// PAT甲级真题1012
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

unordered_map<string,vector<int>> map;
vector<int> q[4];  // A: q[0], C: q[1], M: q[2], E: q[3]
char names[] = "ACME";

int get_rank(vector<int> &a, int score)
{
    int l = 0;
    int r = a.size() -1;
    while(l<r)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid]<=score) l = mid;
        else r = mid -1;
    }
    return a.size() - l;
}


int main()
{
    int n,m;
    cin>>n>>m;
    
    while (n -- )
    {
        string id;
        cin>>id;
        int score[4] = {0};
        for(int i=1;i<4;i++)
        {
            cin>>score[i];
            score[0] += score[i];
        }
        score[0] = round(score[0] / 3.0);
        for(int i=0;i<4;i++)
        {
            map[id].push_back(score[i]);
            q[i].push_back(score[i]);
        }
    }
    
    for (int i = 0; i < 4; i ++ ) sort(q[i].begin(), q[i].end());
    
    
    while (m -- )
    {
        string id;
        cin>>id;
        // cout<<id<<endl;
        if(!map.count(id)) puts("N/A");
        else
        {
            auto &grade = map[id];
            int best = 2021;
            char c;
            for(int i=0;i<4;i++)
            {
                int rk = get_rank(q[i],grade[i]);
                // cout<<rk<<" "<<names[i]<<" "<<best<<" "<<grade[i]<<endl;
                if(best > rk)
                {
                    c = names[i];
                    best = rk;
                }
            }
            cout<<best<<" "<<c<<endl;
        }
    }
    
    return 0;
}