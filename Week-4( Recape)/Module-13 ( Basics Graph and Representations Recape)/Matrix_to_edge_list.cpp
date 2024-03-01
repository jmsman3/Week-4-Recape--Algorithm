#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<pair<int, int>> edgelist;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1 && i != j)
            {
                edgelist.push_back({i, j});
            }
        }
    }

    for (pair<int, int> edge : edgelist)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}

// input:-
// 4
// 1 1 0 0
// 0 1 1 0
// 0 0 1 1
// 0 1 1 1

// output:-
// 1 0
// 2 1
// 3 0
// 3 1
// 3 2
