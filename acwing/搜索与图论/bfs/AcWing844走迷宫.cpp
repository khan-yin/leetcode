#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e2 + 7;
int g[N][N], d[N][N];
int n, m;


int bfs() {
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    queue <PII> q;
    d[1][1] = 0;
    q.push({1, 1});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        // cout<<t.first <<" "<<t.second <<endl;
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            
            // 这样就能保证是最短路，遇到权值已经被计算的则不会再进行运算,即最短
            if (g[x][y] == 0 && d[x][y] == -1) {

                d[x][y] = d[t.first][t.second]  + 1;
                q.push({x, y});
            }
        }

    }
    return d[n][m];
}


int main() {
    cin >> n >> m;
    memset(g, -1, sizeof g);
    memset(d, -1, sizeof d);
    //从1开始则无需判断边界，边界设置为-1
    for (int i = 1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}