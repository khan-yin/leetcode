#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Person
{
    int t;
    int number;
};
int n;
Person p[1005];
bool cmp(Person a,Person b)
{
    return a.t < b.t;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        p[i].number=i;
    }
    sort(p+1,p+n+1,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            cout<<p[i].number;
        }
        else
            cout<<" "<<p[i].number;
        ans+=p[i].t*(n-i);
    }

    cout<<endl;
    printf("%.2f\n",ans*1.0/n);

    return 0;
}