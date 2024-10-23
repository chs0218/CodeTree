#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int n;
int grid[500][500];
bool bVisited[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool IsValidCoord(int y, int x)
{
    if (y < 0) return false;
    if (y >= n) return false;
    if (x < 0) return false;
    if (x >= n) return false;
    return true;
}
int bfs(int startY, int startX, int d)
{
    queue<pair<int, int>> q;
    q.push({ startY, startX });
    bVisited[startY][startX] = true;

    int ret = 1;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newY = curY + dy[i];
            int newX = curX + dx[i];
            if (IsValidCoord(newY, newX) && !bVisited[newY][newX] && 
                abs(grid[newY][newX] - grid[curY][curX]) <= d)
            {
                bVisited[newY][newX] = true;
                q.push({ newY, newX });
                ++ret;
            }
        }
    }
    return ret;
}
int dfs(int y, int x, int d)
{
    int ret = 1;
    bVisited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (IsValidCoord(newY, newX) && !bVisited[newY][newX]
            && abs(grid[y][x] - grid[newY][newX]) <= d)
        {
            ret += dfs(newY, newX, d);
        }
    }
    return ret;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    int nHalf = (n * n + 1) / 2;
    int left = 0, right = 1000000;
    int ans = right;
    while (left <= right)
    {
        memset(bVisited, false, sizeof(bVisited));

        int d = (left + right) / 2;
        int maxColorGrid = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!bVisited[i][j])
                {
                    int nColoredGrid = dfs(i, j, d);
                    maxColorGrid = max(maxColorGrid, nColoredGrid);
                }  
            }
        }

        if (nHalf <= maxColorGrid)
        {
            right = d - 1;
            ans = min(ans, d);
        }
        else
        {
            left = d + 1;
        }
    }
    cout << ans;
    return 0;
}