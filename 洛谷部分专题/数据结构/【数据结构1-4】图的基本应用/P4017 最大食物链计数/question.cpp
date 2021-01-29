#include<bits/stdc++.h>
using namespace std;
int n,m,mp[5005][5005];
int sb[5005];//被吃计数
int nb[5005];//吃别人计数
int ans,r[5005]; 
int dfs(int x){
	//printf("来了");
	if(!nb[x]){//说明搜到了不吃任何东西的生产者，直接回溯，并且初始化状态就是一种情况 
		return 1;
	}
	if(r[x])return r[x];//到x点的路径数搜索过，不需要再搜索 
	int sum=0;//记录到x点的路径数总和 
	for(int i=1;i<=n;i++){
		if(mp[i][x]){
			sum=(sum+dfs(i))%80112002;//搜索下去 
		}
	} 
	return r[x]=sum;//将可以通过x点的路径数记录下来 
}
int main(){ 
	cin>>n>>m;
	//邻接矩阵 
	while(m--){
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
		sb[x]++;//被吃 
		nb[y]++;//吃别人 
	}
	for(int i=1;i<=n;i++){
		if(!sb[i]){//起点是不会被吃的消费者，表示从没有被吃过 
			ans=(ans+dfs(i))%80112002;//所有不会被捕食的消费者食物链和 
		}
	}
	cout<<ans<<endl; 
	return 0;
}
