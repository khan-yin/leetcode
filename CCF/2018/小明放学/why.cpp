#include<iostream>
using namespace std;

int main(){
	int r,y,g,n,state,time;	//红黄绿灯时间  
	cin>>r>>y>>g>>n;
	
	long long sum = 0,pos,a[] = {0,r,r+g+y,r+g}; //sum表示每到一个路口或者红绿灯已经过了多长时间，开始为0 
	//pos表示 在时刻表当中的位置 r+g+y为一个周期 
	while(n-- && cin>>state>>time){
		
		if(state == 0) sum += time;
		else{
			pos = (a[state]-time+sum)%(r+g+y);
			if(pos<r) sum += r-pos;
			else if(pos<r+g) sum += 0;
			else sum +=(r+g+y-pos+r);
		}
	}
	cout<<sum;
	
	return 0;
}
