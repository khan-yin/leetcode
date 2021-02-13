#include<bits/stdc++.h>

using namespace std;
long long A,B,a,N,f[1000005],ans; 
struct data
{
	long long x,y,k;
}n[1000005];
bool cmp(data k1,data k2)
{
	return k1.k<k2.k;
}
long long getfather(long long F)
{
	if(f[F]==F)return F;
	f[F]=getfather(f[F]);
	return f[F];
}
int main()
{
	cin>>A>>B; 
	for(int i=1;i<=B;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=B;i++)
	{
		for(int j=1;j<=B;j++)
		{
			cin>>a;
			if(i<=j&&a!=0)
			{
				n[++N].k=a;
				n[N].x=i;
				n[N].y=j;
			} 
		}
	}
	sort(n+1,n+1+N,cmp);
	for(int i=1;i<=N;i++)
	{
		long long f1=getfather(n[i].x),f2=getfather(n[i].y);
		if(f1!=f2)
		{
			f[f1]=f2;
			if(n[i].k<A)ans+=n[i].k;
			else ans+=A;
		}
	}
	cout<<ans+A<<endl;
	return 0;
}