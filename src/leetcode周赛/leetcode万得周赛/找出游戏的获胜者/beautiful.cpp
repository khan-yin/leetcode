#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k) 
	{
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = i + 1;
		}
		int at = 0;
		while (a.size() > 1) {
			at = (at + k - 1) % a.size();
			a.erase(a.begin() + at);
		}
		return a[0];
	}
};