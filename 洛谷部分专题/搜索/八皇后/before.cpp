#include<iostream>
using namespace std;

int ans[30];
int col[30];
int xsumy[30];
int xdeletey[30];
int n;
int countt = 0;


void dfs(int x)
{
	if (x==n+1)
	{
		if (countt < 3)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		countt++;
	}
	else
	{
		for (int k = 1; k <= n; k++)
		{
			
			if (ans[x] == 0 && col[k] == 0 && xsumy[x + k] == 0 && xdeletey[x - k + n] == 0)
			{
				ans[x] = k;
				col[k] = 1;
				xsumy[x + k] = 1;
				xdeletey[x - k + n] = 1;
				dfs(x + 1);
				ans[x] = 0;
				col[k] = 0;
				xsumy[x + k] = 0;
				xdeletey[x - k + n] = 0;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	dfs(1);
	cout << countt;
	return 0;
}