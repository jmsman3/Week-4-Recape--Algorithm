#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<pair<int, int>> v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for (pair<int, int> child : v[node])
        {
            int child_Node = child.first;
            int child_Cost = child.second;
            if (cost + child_Cost < dis[child_Node])
            {
                dis[child_Node] = cost + child_Cost;
                pq.push({child_Node, dis[child_Node]});
            }
        }
    }
}

int main()
{
    int n, start;
    cin >> n >> start;
    start--; // Adjusting index to zero-based

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
            {
                v[i].push_back({j, 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(start);

    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            if (dis[i] == INT_MAX)
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