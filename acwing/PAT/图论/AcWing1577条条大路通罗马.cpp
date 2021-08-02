// PAT甲级真题1087
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

const int N = 210;
const int inf = 0x3f3f3f3f;
int n,k;

unordered_map<string,int> happy;
unordered_map<string,unordered_map<string,int> > mp; // 存花费
unordered_map<string,string> pre;
unordered_map<string,bool> vis;
unordered_map<string,int> cost;
unordered_map<string,int> maxhappy;
unordered_map<string,int> cnt;
unordered_map<string,int> sum;


void dijkstra(string x)
{

    for(auto& item : happy) cost[item.first] = inf;

    cost[x]=0;
    maxhappy[x]=happy[x];
    cnt[x]=1;
    sum[x]=1;

    for(int i=0;i<n;i++)
    {

        string t;
        // cout<<cost.size()<<endl;
        for(auto& item : cost)
        {
            string city = item.first;
            if(!vis[city]&& (!t.size() || cost[t] > cost[city]))
            {
                t = city;
            }
        }
        // cout<<t<<endl;
        vis[t]=true;
        // cout<<t<<cost[t]<<endl;

        for(auto& item : happy)
        {
            string city = item.first;
            // cout<<city<<endl;
            if(!vis[city])
            {
                // cout<<t<<'-'<<city<<" "<<cost[city]<<' '<<cost[t]<<' '<<mp[t][city]<<endl;
                if(cost[city] > cost[t] + mp[t][city] )
                {
                    cost[city] = cost[t] + mp[t][city];
                    maxhappy[city] = maxhappy[t] + happy[city];
                    cnt[city] = cnt[t] + 1;
                    pre[city] = t;
                    sum[city]=sum[t];
                }
                else if(cost[city]==cost[t]+mp[t][city])
                {
                    sum[city]+=sum[t];
                    if(maxhappy[city] < maxhappy[t] + happy[city])
                    {
                        maxhappy[city] = maxhappy[t] + happy[city];
                        cnt[city] = cnt[t] + 1;
                        pre[city] = t;
                    }
                    else if(maxhappy[city] == maxhappy[t] + happy[city])
                    {
                        if(cnt[city] > cnt[t] + 1)
                        {
                            cnt[city] = cnt[t] + 1;
                            pre[city] = t;
                        }
                    }
                }
            }
        }
    }
}



int main()
{
    string S,T="ROM";
    scanf("%d%d", &n,&k);
    cin>>S;
    happy[S]=0;
    for(int i=0;i<n-1;i++)
    {
        string city;
        int happiness;
        cin>>city>>happiness;
        happy[city]=happiness;
        // cout<<city<<happy[city]<<endl;
    }

    for(auto& item1 : happy)
    {
        for(auto& item2 : happy)
        {
            if(item1.first == item2.first ) mp[item1.first][item2.first]=0;
            mp[item1.first][item2.first]=inf;
        }
    }

    for(int i=0;i<k;i++)
    {
        string a,b;
        int c;
        cin>>a>>b>>c;
        mp[a][b]=min(c,mp[a][b]);
        mp[b][a]=mp[a][b];
        // cout<<a<<' '<<b<<' '<<mp[a][b]<<' '<<mp[b][a]<<endl;
    }


    dijkstra(S);
    //cout<<cost[T]<<endl;

    vector<string> res;
    for(string i=T;i!=S;i=pre[i]) res.push_back(i);


    // for(auto& item1 : happy) cout<<sum[item1.first]<<endl;
    printf("%d %d %d %d\n",sum[T],cost[T],maxhappy[T],maxhappy[T]/(cnt[T]-1));
    cout<<S;
    for(int i=res.size()-1;i>=0;i--) cout<<"->"<<res[i];

    return 0;
}
