#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 1010,M = 31 * 1440 +10;


int cost[24];

double sum[M];

struct Record
{
    int minutes;
    string format_time;
    string state;
    bool operator<(Record& w) const
    {
        return minutes < w.minutes;
    }
};

map<string,vector<Record>> mp;

int main()
{
    for(int i=0;i<24;i++) cin>>cost[i];
    for(int i=1;i<M;i++) sum[i] = sum[i-1] + cost[(i-1) % 1440 / 60] / 100.0; //题目给的每分,求出每元除以100
    int n;
    scanf("%d", &n);
    char name[30],state[30],format_time[30];
    int month,day,hour,minute;
    while (n -- )
    {
        scanf("%s %d:%d:%d:%d %s", &name,&month,&day,&hour,&minute,&state);
        int minutes = (day - 1) * 1440 + hour * 60 + minute;
        sprintf(format_time,"%02d:%02d:%02d",day,hour,minute);
        mp[name].push_back({minutes,format_time,state});
    }
    
    for(auto &person : mp)
    {
        auto name = person.first;
        auto record = person.second;
        // cout<<record.size()<<endl;
        sort(record.begin(),record.end());
        double total = 0;
        for(int i=0;i+1<record.size();i++)
        {
            auto a = record[i], b = record[i+1];
            if(a.state=="on-line"&&b.state=="off-line")
            {
                if(!total) printf("%s %02d\n",name.c_str(),month);
                double c = sum[b.minutes] - sum[a.minutes];
                total+=c;
                cout << a.format_time<<" "<<b.format_time<<" "<<b.minutes-a.minutes<<" "<<"$";
                printf("%.2lf\n",c);
            }
        }
        if(total>0) printf("Total amount: $%.2lf\n",total);
    }
    return 0;
}