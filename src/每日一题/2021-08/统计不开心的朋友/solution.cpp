#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int match[510];
    int level[510][510];
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int cnt=0;
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                level[i][preferences[i][j]] = j;
            }
        }

        for(auto item : pairs)
        {
            int x = item[0];
            int y = item[1];
            match[x]=y;
            match[y]=x;
        }

        for (int x = 0; x < n; ++x)
        {
            int y = match[x];
            int lev = level[x][y];
            for(int i=0;i<lev;i++)
            {
                int u = preferences[x][i];
                int v = match[u];
                if(level[u][x] < level[u][v])
                {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};