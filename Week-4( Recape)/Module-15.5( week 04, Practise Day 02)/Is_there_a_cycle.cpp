#include <bits/stdc++.h>
using namespace std;
const int N = 105; // Adjust N according to the maximum number of nodes
vector<int> adj[N];
int parentArray[N];
bool vis[N];
bool ans;

void dfs(int parent)
{
    vis[parent] = true;
    for (int child : adj[parent])
    {
        if (vis[child] == true && parentArray[parent] != child)
        {
            ans = true;
            return; // If a cycle is detected, immediately return
        }
        if (vis[child] == false)
        {
            parentArray[child] = parent;
            dfs(child);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    // Read the adjacency matrix and construct the adjacency list
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int val;
            cin >> val;
            if (val == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }

    if (ans)
        cout << "1"; // Output "1" if cycle is detected
    else
        cout << "0"; // Output "0" if no cycle is detected
    return 0;
}
