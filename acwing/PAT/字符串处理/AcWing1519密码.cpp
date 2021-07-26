#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
string change(string s)
{
    string res;
    for(char i : s)
    {
        if(i=='1') res +='@';
        else if(i=='0') res +='%';
        else if(i=='l') res += 'L';
        else if(i=='O') res += 'o';
        else res += i;
    }
    return res;
}

string ids[N],pwds[N];

int main()
{
    int n;
    scanf("%d", &n);
    int c = 0;
    string id,pwd;
    for(int i=0;i<n;i++)
    {
        cin>>id>>pwd;
        string newpwd = change(pwd);
        if(newpwd!=pwd)
        {
            c++;
            ids[c]=id;
            pwds[c]=newpwd;
        }
    }
    
    if(!c)
    {
        if(n==1) printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n",n);
    }
    else
    {
        cout<<c<<endl;
        for(int i=1;i<=c;i++)
        {
            cout<<ids[i]<<" "<<pwds[i]<<endl;
        }
    }
    return  0;
}