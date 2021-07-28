// PAT甲级真题1028
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
const int N = 100010;

struct Student
{
    string id;
    string name;
    int score;
};

Student stu[N];



bool cmp1(Student &a, Student &b)
{
    return a.id < b.id;
}


bool cmp2(Student &a, Student &b)
{
    if(a.name != b.name) return a.name < b.name;
    return a.id < b.id;
}


bool cmp3(Student &a, Student &b)
{
    if(a.score != b.score) return a.score < b.score;
    return a.id < b.id;
}


int main()
{
    int n;
    int c;
    scanf("%d%d",&n,&c);
    char id[10], name[10];
    int score;
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %d", id,name,&score);
        stu[i] = {id,name,score};
        // cin>>stu[i].id>>stu[i].name>>stu[i].score;
    }
    
    
    if(c==1)
    {
        sort(stu,stu+n,cmp1);
    }
    else if(c==2)
    {
        sort(stu,stu+n,cmp2);
    }
    else
    {
        sort(stu,stu+n,cmp3);
    }
    
    for(int i=0;i<n;i++) printf("%s %s %d\n",stu[i].id.c_str(),stu[i].name.c_str(),stu[i].score);
    return 0;
}