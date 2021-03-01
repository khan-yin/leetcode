#include<bits/stdc++.h>
using namespace std;
struct country{//定义国家函数，指一个国家的序号和能力。
	int neng_li,bian_hao;
}max1,max2;//两个max表示左与右的最大值 
int n,s;
int main(){
    cin>>n;
    n=1<<n;
    for(int i=1;i<=n/2;i++){
    cin>>s;
    if(max1.neng_li<s){
    	max1.neng_li=s;
    	max1.bian_hao=i;
	}
	}//求左边最大值 
	for(int i=n/2+1;i<=n;i++){
		cin>>s; 
    	if(max2.neng_li<s){
    		max2.neng_li=s;
    		max2.bian_hao=i;
		}
	}//求右边最大值 
	max1.neng_li>max2.neng_li?cout<<max2.bian_hao:cout<<max1.bian_hao;
/*
与下面代码相同：
	if(max1.neng_li>max2.neng_li) cout<<max2.bian_hao;
	else cout<<max1.bian_hao;
	*/ 
    return 0;//完美的结束
}