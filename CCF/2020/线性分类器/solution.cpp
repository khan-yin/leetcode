#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct Node
{
    int x;
    int y;
    char c;
};

int countA=0;
int countB=0;

Node node[100000];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %c",&node[i].x,&node[i].y,&node[i].c);
        if(node[i].c=='A')
            countA++;
        else
        {
            countB++;
        }
        
    }

    for(int i=1;i<=m;i++)
    {
        int w0,w1,w2;
        scanf("%d %d %d",&w0,&w1,&w2);
        int Aup=0,Adown=0,Bdown=0,Bup=0;
		for(int j=1;j<=n;j++)
		{
			if((w0+w1*node[j].x+w2*node[j].y)>0&&node[j].c=='A')			
			Aup++;
			else if((w0+w1*node[j].x+w2*node[j].y)<0&&node[j].c=='A')	
			Adown++;
			else if((w0+w1*node[j].x+w2*node[j].y)>0&&node[j].c=='B')
			Bup++;	
			else if((w0+w1*node[j].x+w2*node[j].y)<0&&node[j].c=='B')
			Bdown++;			
		}		
		if ((Aup==countA&&Bdown==countB)||(Adown==countA&&Bup==countB))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
    }
    return 0;
}
