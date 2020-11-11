#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
double num[10005];
int main(){
	int n;
	set<int>s;
	cin>>n;
	for(int i=0;i<n;i++){
		int a ;
		double b;
		cin>>a>>b;
		num[a]+=b;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int a ;
		double b;
		cin>>a>>b;
		num[a]+=b;
	}
    int count=0;
    for(int i=0;i<10005;i++){
        if(num[i]!=0){
            count++;
        }
    }
	cout<<count;
	for(int i=10000;i>=0;i--){
		if(num[i]!=0){
            printf(" %d %0.1f", i, num[i]);
			//cout<<" "<<i<<" "<<num[i];
		} 
	}
	return 0;
	
} 