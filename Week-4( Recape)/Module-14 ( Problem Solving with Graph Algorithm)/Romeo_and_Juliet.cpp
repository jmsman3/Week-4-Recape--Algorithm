#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int dis[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] + 1; //destimation e level update
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    // vector<int> v[n]; aita globally already declair kora ase
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int src, final_des, k_step;
    cin >> src >> final_des >> k_step;

    bfs(src);

    if (dis[final_des] != -1 && dis[final_des] <= k_step * 2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}