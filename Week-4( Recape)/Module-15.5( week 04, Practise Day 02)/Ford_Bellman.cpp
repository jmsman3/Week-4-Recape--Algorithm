#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int INF = 30000; // Represents infinity (path length not existent)

vector<int> bellmanFord(int n, const vector<Edge> &edges, int source)
{
    vector<int> dist(n + 1, INF); // Initialize distances to all vertices as infinity
    dist[source] = 0;             // Distance to source vertex is 0

    // Relaxation step
    for (int i = 0; i < n - 1; ++i)
    {
        for (const Edge &edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.c;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }

    vector<int> shortest_paths = bellmanFord(n, edges, 1);

    for (int i = 1; i <= n; ++i)
    {
        if (shortest_paths[i] == INF)
        {
            cout << "30000 ";
        }
        else
        {
            cout << shortest_paths[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
