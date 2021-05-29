#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string get(int x)
    {
        string s="";
        for(int i=31;i>=0;i--)
        {
            s += (x>>i&1) + '0';
        }
        return s;
    }
    int sum(string a,string b)
    {
        // cout<<a<<endl;
        // cout<<b<<endl;
        int c=0;
        for(int i=31;i>=0;i--)
        {
            if(a[i]!=b[i])
            {
                c+=(1<<(31-i));
                // cout<<(1<<(31-i))<<endl;
            }
        }
        return c;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        for(int i:nums1) m1[i]++;
        for(int i:nums2)
        {
            if(m1[i]>0) m1[i]--;
            else m2[i]++;
        }
        vector<string> s1,s2;
        for(auto item : m1)
        {
            if(item.second>0)
                s1.push_back(get(item.first));
        }
        for(auto item : m2)
        {
            if(item.second>0)
                s2.push_back(get(item.first));
        }
        sort(s2.begin(),s2.end());
        sort(s1.begin(),s1.end());
        int res=0;
        for(int i=0;i<s1.size();i++)
        {
            auto it =lower_bound(s2.begin(),s2.end(),s1[i]);
            if(it!=s2.end()&&it!=s2.begin()) 
            {
                auto pre = it;
                pre--;
                int k1 = sum(*pre,s1[i]);
                int k2 = sum(*it,s1[i]);
                if(k1<k2)
                {
                    res+=k1;
                    s2.erase(pre);
                }
                else
                {
                    res+=k2;
                    s2.erase(it);
                }
            }
            else if(it==s2.begin())
            {
                res += sum(*it,s1[i]);
                s2.erase(it);
            }
            else 
            {
                auto pre = it;
                pre--;
                res += sum(*pre,s1[i]);
                s2.erase(pre);
            }
        }
        return (int)res;
    }
};