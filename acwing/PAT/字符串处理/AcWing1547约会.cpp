#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const char days[8][10] ={"MON","TUE","WED","THU","FRI","SAT","SUN"};


int main()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    char r1;
    int r2;
    int r3;
    int i=0,j=0,k=0;
    for(i=0;i<s1.size()&&i<s2.size();i++)
    {
        if(s1[i]==s2[i] && s1[i]>='A'&&s1[i]<='G') break;
    }
    // cout<<s1[i]<<endl;
    r1=s1[i];
    
    for(j=i+1;j<s1.size()&&j<s2.size();j++)
    {
        if(s1[j]==s2[j]&&(s1[j]>='A'&&s1[j]<='N' || s1[j]>='0'&&s1[j]<='9')) break;
    }
    // cout<<s1[j]<<endl;
    if(s1[j]>='A'&&s1[j]<='Z') r2 = s1[j]-'A' + 10;
    else r2 = s1[j]-'0';
    
    
    
    for(k = 0;k<s3.size()&&k<s4.size();k++)
    {
        if(s3[k]==s4[k] && (s3[k]>='A'&&s3[k]<='Z' || s3[k]>='a'&&s3[k]<='z')) break;
    }
    r3 = k;
    
    cout<<days[r1-'A']<<" ";
    printf("%02d:%02d",r2,r3);
    
    
    return 0;
}