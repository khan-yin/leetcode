#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct Node
{
    int x;
    int y;
};

Node node[1005];

int scores[5];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&node[i].x,&node[i].y);
    }


    for(int i=1;i<=n;i++)
    {
        int x = node[i].x;
        int y = node[i].y;
        int cnt=0;
        int score=0;
        for(int j=1;j<=n;j++)
        {
            if(node[j].x==x&&node[j].y==y-1)
                cnt++;
            else if(node[j].x==x&&node[j].y==y+1)
                cnt++;
            else if(node[j].x==x+1&&node[j].y==y)
                cnt++;
            else if(node[j].x==x-1&&node[j].y==y)
                cnt++;
            else if(node[j].x==x+1&&node[j].y==y+1)
                score++;
            else if(node[j].x==x+1&&node[j].y==y-1)
                score++;
            else if(node[j].x==x-1&&node[j].y==y-1)
                score++;
            else if(node[j].x==x-1&&node[j].y==y+1)
                score++;
        }
        if(cnt==4)
        {
            scores[score]++;
        }
    }

    cout << scores[0] << endl;
	cout << scores[1] << endl;
	cout << scores[2] << endl;
	cout << scores[3] << endl;
	cout << scores[4] << endl;
    return 0;
}