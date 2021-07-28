// PAT甲级真题1039
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 40010;

unordered_map<string,vector<int>> stu;

int main()
{
    int n,k;//分别表示需要查询的学生数量以及课程数量。
    cin>>n>>k;
    
    for(int i=0;i<k;i++)
    {
        int id,cnt;
        cin>>id>>cnt;
        while(cnt--)
        {
            string name;
            cin>>name;
            stu[name].push_back(id);
        }
    }
    
    while(n--)
    {
        string name;
        cin>>name;
        cout<<name<<" "<<stu[name].size();
        sort(stu[name].begin(),stu[name].end());
        for(int id : stu[name])
        {
            cout<<" "<<id;
        }
        cout<<endl;
    }
    return 0;
}