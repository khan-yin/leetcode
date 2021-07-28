// PAT甲级真题1025
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 110;

struct Student
{
    string id;
    int score;
    int location_number;
    int final_rank;
    int local_rank;
    // Student越大越在前面
    bool operator<(const Student& s) const
    {
        if(score != s.score) return score>s.score;
        return  id < s.id;
    }
};

vector<Student> students;
vector<Student> regions[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        for (int j = 0; j < m; j ++ )
        {
            string id;
            int score;
            cin>>id>>score;
            regions[i].push_back({id,score,i,0,0});
        }
        auto & region = regions[i];
        sort(region.begin(),region.end());
        for(int j=0;j<region.size();j++)
        {
            if(!j || region[j].score!=region[j-1].score) 
                region[j].local_rank = j+1;
            else
                region[j].local_rank = region[j-1].local_rank;
            students.push_back(region[j]);
        }
    }
    
    sort(students.begin(),students.end());
    for(int i=0;i<students.size();i++)
    {
        if(!i || students[i].score!=students[i-1].score) 
            students[i].final_rank = i+1;
        else
            students[i].final_rank = students[i-1].final_rank;
    }
    cout<<students.size()<<endl;
    
    for(auto & stu : students)
    {
        cout<<stu.id<<" "<< stu.final_rank<<" "<< stu.location_number<<" "<<stu.local_rank<<endl;
    }
    
    return 0;
}