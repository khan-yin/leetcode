// PAT甲级真题1111
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

const int N = 510;

int n, m, S, T;
int d1[N][N], d2[N][N];
int dist1[N], dist2[N], pre[N];
bool st[N];

pair<int, string> dijkstra(int d1[][N], int d2[][N], int type)
{
    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);
    memset(st, 0, sizeof st);
    dist1[S] = dist2[S] = 0;

    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (!st[j] && (t == -1 || dist1[t] > dist1[j]))
                t = j;
        st[t] = true;
        for (int j = 0; j < n; j ++ )
        {
            int w;
            if (type == 0) w = d2[t][j];
            else w = 1;

            if (dist1[j] > dist1[t] + d1[t][j])
            {
                dist1[j] = dist1[t] + d1[t][j];
                dist2[j] = dist2[t] + w;
                pre[j] = t;
            }
            else if (dist1[j] == dist1[t] + d1[t][j])
            {
                if (dist2[j] > dist2[t] + w)
                {
                    dist2[j] = dist2[t] + w;
                    pre[j] = t;
                }
            }
        }
    }

    vector<int> path;
    for (int i = T; i != S; i = pre[i]) path.push_back(i);

    pair<int, string> res;
    res.first = dist1[T];
    res.second = to_string(S);
    for (int i = path.size() - 1; i >= 0; i -- )
        res.second += " -> " + to_string(path[i]);
    return res;
}

int main()
{
    cin >> n >> m;

    memset(d1, 0x3f, sizeof d1);
    memset(d2, 0x3f, sizeof d2);

    while (m -- )
    {
        int a, b, t, c, d;
        cin >> a >> b >> t >> c >> d;
        if (d1[a][b] > c) d1[a][b] = c, d2[a][b] = d;
        else if (d1[a][b] == c && d2[a][b] > d) d2[a][b] = d;
        if (!t)
        {
            if (d1[b][a] > c) d1[b][a] = c, d2[b][a] = d;
            else if (d1[b][a] == c && d2[b][a] > d) d2[b][a] = d;
        }
    }

    cin >> S >> T;

    auto A = dijkstra(d1, d2, 0);
    auto B = dijkstra(d2, d1, 1);

    if (A.second != B.second)
    {
        printf("Distance = %d: %s\n", A.first, A.second.c_str());
        printf("Time = %d: %s\n", B.first, B.second.c_str());
    }
    else
    {
        printf("Distance = %d; Time = %d: %s\n", A.first, B.first, A.second.c_str());
    }

    return 0;
}