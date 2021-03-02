#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N,T;
struct Gold
{
    int weight;
    int value;
};

Gold gold[105];
bool cmp(Gold a,Gold b)
{
    return (a.value*1.0/a.weight) > (b.value*1.0/b.weight);
}

int main()
{
    cin>>N>>T;
    for(int i=1;i<=N;i++)
    {
        scanf("%d %d",&gold[i].weight,&gold[i].value);
    }

    sort(gold+1,gold+N+1,cmp);
    double total = 0;
    for(int i=1;i<=N;i++)
    {
        if(T>=gold[i].weight)
        {
            total+=gold[i].value;
            T-=gold[i].weight;
        }
        else 
        {
            total+=gold[i].value*T*1.0/gold[i].weight;
            T=0;
        }
        if(T<=0)
            break;
    }

    printf("%.2f\n",total);

    return 0;
}