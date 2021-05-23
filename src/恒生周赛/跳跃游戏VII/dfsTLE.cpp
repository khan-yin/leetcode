#include<string>
using namespace std;

class Solution {
public:
    bool dfs(int index,string s,int& minJump, int& maxJump)
    {
        if(index==s.size()-1)
        {
            return true;
        }
        bool flag=false;
        for(int j=minJump;j<=maxJump;j++)
        {
            if(index+j<s.size()&&s[index+j]=='0')
                flag=dfs(index+j,s,minJump,maxJump);
        }
        return flag;
    }
    bool canReach(string s, int minJump, int maxJump) {
        return dfs(0,s,minJump,maxJump);
    }
};