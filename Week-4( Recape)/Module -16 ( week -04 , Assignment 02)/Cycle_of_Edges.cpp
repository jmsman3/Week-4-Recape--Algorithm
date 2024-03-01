#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
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

class Edge
{
public:
    int u, v;
    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    vector<Edge> Edgelist;

    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        Edgelist.push_back(Edge(u, v));
    }

    int cycleEdges = 0;
    for (Edge ed : Edgelist) // int ed er bodol e (Edge ed :),
    // Edge neje e ekta data type
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);

        if (leaderU == leaderV)
        {
            cycleEdges++;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
        }
    }

    cout << cycleEdges << endl;

    return 0;
}
