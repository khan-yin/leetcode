#include <iostream>
using namespace std;
char a[1000];
char l[1000];
char r[1000];
int i,j;
void dfs(char x){
	int s;
	cout<<x;//直接输出
	s=x;//直接把a[i]的ASCLL码当作数组的指针
	if(l[s]!='*')dfs(l[s]);//一定要判断不为*
	if(r[s]!='*')dfs(r[s]);//先左后右
	return;
}
int main(){
	int k,n,s;
	cin>>n;
	for(i=1;i<=n;i++){
	    cin>>a[i];
		s=a[i];//ASCLL码当作数组指针
		cin>>l[s]>>r[s];
	}
	dfs(a[1]);
}