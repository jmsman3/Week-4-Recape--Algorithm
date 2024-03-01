#include <bits/stdc++.h>
using namespace std;
int const N = 101;
vector<int> v[N];
int des_from_src[N];
int des_from_dis[N];
bool vis[N];

void bfs(int s, int track)
{
    queue<int> q;
    q.push(s);
    if (track == 1)
        des_from_src[s] = 0;
    else if (track == 2)
        des_from_dis[s] = 0;
    vis[s] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                if (track == 1)
                    des_from_src[child] = des_from_src[par] + 1;
                else if (track == 2)
                    des_from_dis[child] = des_from_dis[par] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        int n, e;
        cin>>n>>e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int s, d;      // src and distination
        cin >> s >> d; // bsf deye ekbar s distination sum + d er distination sum bahir korbo (both er maximum ta bahir korbo)

        memset(vis, false, sizeof(vis));
        memset(des_from_src, -1, sizeof(des_from_src));
        bfs(s, 1);

        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        memset(des_from_dis, -1, sizeof(des_from_dis));
        bfs(d, 2);

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int val = des_from_src[i] + des_from_dis[i];
            ans = max(ans, val);
        }

        cout << "Case " << cs++<< ": " << ans << endl;

        for (int i = 0; i < n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}