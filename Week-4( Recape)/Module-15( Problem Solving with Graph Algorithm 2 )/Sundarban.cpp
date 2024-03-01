#include <bits/stdc++.h>
using namespace std;
const int N = 50;
char aa[N][N];
int dis[N][N];
bool vis[N][N];
int n;

vector<pair<int, int> > d;

int valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < n);
}

void bfs(int si, int sj)
{
    

    queue<pair<int, int> > q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && aa[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{   

    d.push_back({0, 1});
    d.push_back({0, -1});
    d.push_back({-1, 0});
    d.push_back({1, 0});
    int si, sj;
    int di, dj;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> aa[i][j];
                if (aa[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (aa[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj] << " ";
    }
    return 0;
}