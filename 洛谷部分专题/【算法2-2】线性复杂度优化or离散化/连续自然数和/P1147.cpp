#include<iostream>
#include<cstdio>
using namespace std;
long long n,a,b,c;
int main() {
	scanf("%d",&n);
	for(a=1; a<=n-1; a++) {
		for(b=a+1; b<=n; b++) {
			c=(b-a)+1;
			if(a*c>=n) break;//剪枝
			if(((a+b)*c/2)==n) {
				printf("%d ",a);
				printf("%d\n",b);
				break;
			}
		}
	}
	return 0;
}