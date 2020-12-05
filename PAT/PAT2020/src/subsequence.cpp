#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

bool getAns(string temp,string sub)
    {
        int k=0;
        int i=0;
        while(k<temp.length()&&i<sub.length())
        {
            
            int t=temp.find(sub[i],k);
            if(t==-1||k>t)
                return false;
            k=t;
            i++;
        }
        return true;
    }

int main()
{
    string str;
    string sub;
    string ans="";
    int sl=sub.length();
    cin>>str;
    cin>>sub;
    for(int i=0;i<str.length();i++)
    {
        for(int j=i+sl;j<=str.length();j++)
        {
            string temp=str.substr(i,j);
            cout<<temp<<endl;
            bool flag=getAns(temp,sub);
            if(ans.length()==0&&flag)
            {
                ans=temp;
            }
            else
            {
                if(flag&&ans.length()>temp.length())
                {
                    ans=temp;
                }
            }
        }
    }
    // cout<<ans;

    return 0;
}