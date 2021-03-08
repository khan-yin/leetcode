#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;

map<int,map<int,int> > boxs;
int main()
{
    int n,q;
    cin>>n>>q;

    while(q--)
    { 
        int type,i,j,k;
        cin>>type>>i>>j;
        if(type==1)
        {
            cin>>k;
            boxs[i][j]=k;
        }
        else 
        {
            cout<<boxs[i][j]<<endl;
        }
    }
    return 0;
}