#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int analysisName(string name)
    {
        int f=name.find("(");
        int l=name.find(")");
        string val=name.substr(f+1,l-f-1);
        // cout<<val<<endl;
        return stoi(val);
    }


    void dfs(int& cnt,map<string,set<string>>& relatednames,set<string>& isvisited,vector<string>& res,string& relatename,map<string,int>& name_times)
    {
        set<string>lis =relatednames[relatename];
        for(auto relatename:lis)
        {
            if(isvisited.find(relatename)==isvisited.end())
            {
                cnt+=name_times[relatename];
                // as.insert(relatename);
                isvisited.insert(relatename);
                dfs(cnt,relatednames,isvisited,res,relatename,name_times);
            }
        }
    }
    
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        map<string,int> name_times;
        map<string,set<string>> relatednames;
        for(auto name:names)
        {
            int c=analysisName(name);
            string n=name.substr(0,name.find("("));
            auto it = relatednames.find(n);
            if(it==relatednames.end())
            {
                set<string> temp;
                temp.insert(n);
                relatednames.insert(pair<string, set<string>>(n,temp));
            }
            // cout<<n<<endl;
            name_times.insert(pair<string,int>(n,c));
        }
        // cout<<relatednames.size();
        // cout<<name_times.size();
        // for(auto i:name_times)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        for(auto s:synonyms)
        {
            int left=s.find("(");
            int dou=s.find(",");
            int right=s.find(")");
            string name1=s.substr(left+1,dou-left-1);
            // cout<<name1<<endl;
            string name2=s.substr(dou+1,right-dou-1);
            // cout<<name2<<endl;
            // map<string, vector<string>>::iterator it;
	        auto it1 = relatednames.find(name1);
            auto it2 = relatednames.find(name2);
            
            if(it1!=relatednames.end())
            {
                it1->second.insert(name2);
                if(it2!=relatednames.end())
                {
                    it2->second.insert(name1);
                }
                else
                {
                    set<string> temp;
                    temp.insert(name1);
                    temp.insert(name2);
                    relatednames.insert(pair<string,set<string>>(name2,temp));
                }
            }
            else{
                set<string> temp;
                temp.insert(name1);
                temp.insert(name2);
                relatednames.insert(pair<string,set<string>>(name1,temp));
                if(it2!=relatednames.end())
                {
                    it2->second.insert(name1);
                }
                else
                {
                    set<string> temp;
                    temp.insert(name1);
                    temp.insert(name2);
                    relatednames.insert(pair<string,set<string>>(name2,temp));
                }
            }
        }
        // for(auto i:relatednames)
        // {
        //     cout<<i.first<<" ";
        //     for(auto k:i.second)
        //     {
        //         cout<<k<<" ";
        //     }
        //     cout<<endl;
        // }
        
        set<string> isvisited;
        vector<string> res;
        
        for(auto it:name_times)
        {
            int cnt=0;
            string name=it.first;
            // cout<<name<<endl;
            if(isvisited.find(name)!=isvisited.end())
                continue;
            // set<string> as;
            // as.insert(name);
            // string truename=*(it.second.begin());
            // cout<<truename<<endl;
            // cout<<"for:"<<name<<" "<<truename<<endl;
            isvisited.insert(name);
            cnt+=name_times[name];
            for(auto relatename:relatednames[name])
            {
                if(isvisited.find(relatename)==isvisited.end())
                {
                    // isvisited.insert(relatename);
                    dfs(cnt,relatednames,isvisited,res,relatename,name_times);
                }
            }
            if(cnt==0)
                continue;
            // string truename=*(as.begin());
            string resname=name+"("+std::to_string(cnt)+")";
            // cout<<resname<<" ";
            res.push_back(resname);
        }
        // cout<<relatednames.size();
        // cout<<isvisited.size();
        // for(auto i:isvisited)
        // {
        //     cout<<i<<endl;
        // }
        // set<string> st(res.begin(), res.end());
        // res.assign(st.begin(), st.end());
        return res;
    }
};