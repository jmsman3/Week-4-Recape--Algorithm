#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Since it's an undirected graph
}

bool isConnected(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1); // Start BFS from vertex 1

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = true;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            return false; // If any vertex is not visited, the graph is not connected
        }
    }

    return true; // If all vertices are visited, the graph is connected
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    if (isConnected(adj, n))
    {
        cout << "YES" << endl; // If the graph is connected
    }
    else
    {
        cout << "NO" << endl; // If the graph is not connected
    }

    return 0;
}
