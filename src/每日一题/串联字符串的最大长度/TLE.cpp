#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    int res = 0;
    void dfs(string s,int cnt,vector<string>& arr,unordered_map<char,int> m)
    {
        if(cnt==arr.size()) 
        {
            if(s.size()>res) cout<<s<<endl;
            res = s.size() > res ? s.size(): res;
            return;
        }

        for(string a : arr)
        {
            //check是否可加
            bool flag=true;
            int ed = 0;
            for(int i=0;i<a.size();i++)
            {
                if(m[a[i]]>0)
                {
                    flag=false;
                    break;
                }
                m[a[i]]++;
                ed++;
            }

            for(int i=0;i<ed;i++) m[a[i]]--;
            //如果可加
            if(flag)
            {
                for(char x : a) m[x]++;
                dfs(s+a,cnt+1,arr,m);
                //恢复现场
                for(char x : a) m[x]--;
            }   
            //不加
            dfs(s,cnt+1,arr,m);
        }

    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> m;
        dfs("",0,arr,m);
        return res;
    }
};