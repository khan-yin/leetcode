#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct Request
{
    int start_h=0;
    int start_m=0;
    int start_s=0;
    int end_h=0;
    int end_m=0;
    int end_s=0;
    int length=0;
    int starttime = 0;
    int endtime = 0;
};

bool cmp(Request a,Request b)
{
    if(a.endtime!=b.endtime)
        return a.endtime>b.endtime;
    else
        return a.starttime>b.starttime;
}


Request req[2005];
vector<Request> res;
// hh:mm:ss hh:mm:ss
int main()
{
    int n;
    scanf("%d",&n);
    string a;
    getchar();
    for(int i=1;i<=n;i++)
    {
        getline(cin,a);
        req[i].start_h = (a[0]-'0')*10+a[1]-'0';
        req[i].start_m = (a[3]-'0')*10+a[4]-'0';
        req[i].start_s = (a[6]-'0')*10+a[7]-'0';
        req[i].end_h = (a[9]-'0')*10+a[10]-'0';
        req[i].end_m = (a[12]-'0')*10+a[13]-'0';
        req[i].end_s = (a[15]-'0')*10+a[16]-'0';
        req[i].starttime= req[i].start_h*60*60+req[i].start_m*60+req[i].start_s;
        req[i].endtime = req[i].end_h*60*60+req[i].end_m*60+req[i].end_s;
        // req[i].length = (req[i].end_h*60*60+req[i].end_m*60+req[i].end_s) - (req[i].start_h*60*60+req[i].start_m*60+req[i].start_s);
        // cout<<req[i].start_h<<":"<<req[i].start_m<<":"<<req[i].start_s<<":"<<req[i].end_h<<":"<<req[i].end_m<<":"<<req[i].end_s<<endl;
    }
    sort(req+1,req+1+n,cmp);
    // cout<<"q"<<endl;
    int end=23*60*60+59*60+59;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        // cout<<req[i].start_h<<":"<<req[i].start_m<<":"<<req[i].start_s<<":"<<req[i].end_h<<":"<<req[i].end_m<<":"<<req[i].end_s<<endl;
        if(req[i].endtime<=end)
        {
            cnt++;
            end = req[i].starttime;
            // cout<<"good"<<endl;
        }
    }
    cout<<cnt;

    return 0;
}