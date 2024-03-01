#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> v[N];
int dis[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : v[node])
        {
            if (dis[child] == -1)
            {
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, start;
    cin >> n >> start;
    start--; // Adjusting index to zero-dhore

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
            {
                v[i].push_back(j);
            }
        }
    }

    memset(dis, -1, sizeof(dis));

    bfs(start);

    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            if (dis[i] == -1)
                cout << -1 << " ";
            else
                cout << dis[i] << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    return 0;
}
