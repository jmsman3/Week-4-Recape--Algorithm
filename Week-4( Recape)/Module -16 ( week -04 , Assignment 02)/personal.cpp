#include <bits/stdc++.h>
using namespace std;
//--------------------------------------------------------------------------
const int N = 135 + 5;
int parent[N];
int group_size[N];

void dsu_intitialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1) return node;
    return parent[node] = dsu_find(parent[node]); 
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
//--------------------------------------------------------------------------
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
//----------------------------------------------------------------------
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_intitialize(n);
    vector<Edge> Edgelist;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edgelist.push_back(Edge(u, v, w));
    }
    //--------------------------------------------------------------------
    sort(Edgelist.begin(), Edgelist.end(), cmp);
    int sum_totalCost = 0;
    //----------------------------------------------------------------------
    for (Edge ed : Edgelist) // int ed er bodol e (Edge ed :),
    // Edge neje e ekta data type
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);

        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            sum_totalCost += ed.w;
        }
    }
    cout << sum_totalCost << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int n, m;

bool vis[1005][1005];
int dis[1005][1005];
char a[20][20];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int prothom = par.first;
        int secondd = par.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = prothom + d[i].first;
            int cj = secondd + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[prothom][secondd] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    bfs(si, sj);

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 'A' && dis[i][j] == 'B')
            {
                cout <<"YES";
            }
        }
    }

    return 0;
}