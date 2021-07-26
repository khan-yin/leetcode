#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1001;

int main()
{
    int n;
    scanf("%d", &n);
    string girl_id,girl_name,boy_id,boy_name;
    int girl_score,boy_score;
    
    string name,sex,id;
    int score;
    for(int i=0;i<n;i++)
    {
        cin>>name>>sex>>id>>score;
        if(sex=="F")
        {
            if(girl_id.empty() || girl_score<score)
            {
                girl_name = name;
                girl_id = id;
                girl_score = score;
            }
        }
        else
        {
            if(boy_id.empty() || boy_score>score)
            {
                boy_name = name;
                boy_id = id;
                boy_score = score;
            }
        }
    }
    if(girl_id.empty()) cout << "Absent"<<endl;
    else cout<<girl_name<<" "<<girl_id<<endl;
    
    if(boy_id.empty()) cout << "Absent"<<endl;
    else cout<<boy_name<<" "<<boy_id<<endl;
    
    if(boy_id.empty() || girl_id.empty()) cout<<"NA"<<endl;
    else cout<< girl_score - boy_score<<endl;
    return 0;
}