#include<string>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool isvisited[10];
    int size;
    set<string> res;
    string s;
    void dfs(int step,string str)
    {
        if(step==size)//元素遍历完全
        {
            //去重复
            // vector<string>::iterator it = find(res.begin(), res.end(), str);
            // if(it==res.end())
            res.insert(str);
            return;
        }

        for(int i=0;i<size;i++)
        {
            if(!isvisited[i])
            {
                isvisited[i]=true;
                dfs(step+1,str+s[i]);
                isvisited[i]=false;
            }
        }

    }

    vector<string> permutation(string s) {
        size = s.size();
        this->s=s;
        dfs(0,"");
        vector<string> ans;
        for(string st : res)
        {
            ans.push_back(st);
        }
        return ans;
    }
};