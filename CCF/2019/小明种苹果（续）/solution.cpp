#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

bool isdrop[1005];
int apple[1005];
int D=0;
int E=0;

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        scanf("%d",&apple[i]);
        for(int j=1;j<=m-1;j++)
        {
            int x;
            scanf("%d",&x);
            if(x<=0)
            {
                apple[i]+=x;
            }
            else
            {
                if(apple[i]!=x)
                {
                    isdrop[i]=true;
                    apple[i]=x;
                }
            }
        }
        ans+=apple[i];
    }

    isdrop[0]=isdrop[n];
    isdrop[n+1]=isdrop[0];
    for(int i=1;i<=n;i++)
    {
        if(isdrop[i])
            D++;
        if(isdrop[i-1]&&isdrop[i]&&isdrop[i+1])
            E++;
    }

    cout<<ans<<" "<<D<<" "<<E<<endl;
    return 0;
}