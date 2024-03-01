#include <bits/stdc++.h>
using namespace std;


struct Point
{
    int x, y;
};

bool isValid(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

vector<vector<char>> findPath(vector<vector<char>> &grid, Point start, Point end)
{
    int n = grid.size();
    vector<vector<char>> path = grid;

    queue<Point> q;
    q.push(start);

    // Possible moves: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y)
        {
            // Found the destination
            return path;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isValid(newX, newY, n) && (path[newX][newY] == '.' || (newX == end.x && newY == end.y)))
            {
                // Move the ball to the new position
                path[newX][newY] = '+';
                q.push({newX, newY});
            }
        }
    }

    // No path found
    path.clear();
    return path;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    Point start, end;

    // Input grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '@')
            {
                start = {i, j};
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'X')
            {
                end = {i, j};
            }
        }
    }

    vector<vector<char>> path = findPath(grid, start, end);

    if (path.size() > 0)
    {
        cout << "Y" << endl;
        // Print the path
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << path[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}
