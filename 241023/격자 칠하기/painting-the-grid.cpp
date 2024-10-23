#include <iostream>
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
int dfs(int y, int x, int startY, int startX, int d)
{
    int ret = 1;
    bVisited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (IsValidCoord(newY, newX) && !bVisited[newY][newX]
            && abs(grid[startY][startX] - grid[newY][newX]) <= d)
        {
            ret += dfs(newY, newX, startY, startX, d);
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

    bool bEscape = false;
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
                    int nColoredGrid = dfs(i, j, i, j, d);
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