#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n,m;
int stu[2000006];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>stu[i];
    }
    for(int i=1;i<=m;i++)
    {
        int number;
        cin>>number;
        cout<<stu[number]<<endl;
    }
    return 0;
}