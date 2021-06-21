#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool vis[11]={0};
    int turnedOn;
    set<string> res;
    void dfs(int n)
    {
        if(n==turnedOn)
        {
            string s="";
            int hour = 0;
            int clock = 0;
            for(int i=1;i<5;i++)
            {
                // cout<<i<<vis[i]<<endl;
                if(vis[i]) hour += 1<<(i-1);
                if(hour>=12) return;
            }
            s+=to_string(hour);
            s+=':';
            for(int i=5;i<11;i++)
            {
                // cout<<i<<vis[i]<<endl;
                if(vis[i]) clock += 1<<(i-5);
                if(clock>59) return;
            }
            
            if(clock<10) s+='0';
            s+=to_string(clock);
            // cout<<s<<endl;
            res.insert(s);
            return;
        }

        for(int i=10;i>0;i--)
        {
            if(vis[i]) continue;
            vis[i]=true;
            dfs(n+1);
            vis[i]=false;
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        this->turnedOn = turnedOn;
        dfs(0);
        vector<string> ans;
        for(string s : res) ans.push_back(s);
        return ans;
    }
};