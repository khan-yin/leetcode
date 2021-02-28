#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int r,y,g;//红灯，黄灯，绿灯
// k=0 表示经过了一段道路，耗时 t 秒，
// k=1、2、3 时，分别表示看到了一个红灯、黄灯、绿灯，
// 且倒计时显示牌上显示的数字是 t，此处 t 分别不会超过 r、y、g
// 黄灯，车辆不许通过

inline int cost(int k,int t)
{
    int c=0;
    switch (k)
    {
        case 0: c+=t; break;
        case 1: c+=t; break;
        case 2: c+=t+r; break;
        default: c+=0;break;
    }
    return c;
}

int main()
{
    cin>>r>>y>>g;
    int n;
    int total=0;
    cin>>n;
    int k,t;
    while(n--)
    {
        cin>>k>>t;
        total+=cost(k,t);
    }
    cout<<total<<endl;
    return 0;
}