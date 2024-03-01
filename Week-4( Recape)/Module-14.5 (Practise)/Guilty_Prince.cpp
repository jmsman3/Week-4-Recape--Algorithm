#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char a[N][N];
int n, m;
bool vis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int ci, int cj)
{
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

int cnt;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 1; // test case 1 theke suru korte hobe;
    int si, sj;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        cnt=0;

        for (int i = 0; i < n; i++)    // memset(vis, false, sizeof(vis)); 
        //memset deye o kora jai;
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
            }
        }

        dfs(si, sj);

        cout << "Case " << cs++ << ": " << cnt << endl;
    }
    return 0;
}