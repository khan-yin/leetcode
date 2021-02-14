#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int cnt_pass=0;
int cnt_in=0;
int n,k,t,xl,yd,xr,yu;
inline bool ispass(int x,int y)
{
    if(x>=xl&&x<=xr&&y>=yd&&y<=yu)
        return true;
    return false;
}
int main()
{
    scanf("%d %d %d %d %d %d %d",&n,&k,&t,&xl,&yd,&xr,&yu);
    for(int i=1;i<=n;i++)
    {
        int temp_pass=0;
        bool haspass=false;
        bool hasin=false;
        for(int j=1;j<=t;j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(ispass(x,y))
            {
                temp_pass++;
                haspass=true;
                if(temp_pass>=k)
                    hasin=true;
            }
            else
            {
                temp_pass=0;
            }
            
        }
        // cout<<temp_pass<<endl;
        if(hasin)
        {
            cnt_pass++;
            cnt_in++;
        }
        else if(haspass)
            cnt_pass++;
    }
    printf("%d\n",cnt_pass);
    printf("%d\n",cnt_in);
    return 0;
}