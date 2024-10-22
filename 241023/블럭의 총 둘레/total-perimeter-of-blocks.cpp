#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int n;
int grid[102][102];
bool bVisited[102][102];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool IsValidCoord(int y, int x)
{
    if (x < 0) return false;
    if (y < 0) return false;
    if (x > 101) return false;
    if (y > 101) return false;
    return true;
}
void Initialize()
{
    memset(bVisited, false, sizeof(bVisited));

    queue<pair<int, int>> q;
    grid[0][0] = -1;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newY = cur.first + dy[i];
            int newX = cur.second + dx[i];
            if (IsValidCoord(newY, newX) && grid[newY][newX] == 0 && !bVisited[newY][newX])
            {
                bVisited[newY][newX] = true;
                grid[newY][newX] = -1;
                q.push({ newY, newX });
            }
        }
    }
}
int main() {
    cin >> n;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        int r, c;
        cin >> r >> c;
        grid[r][c] = 1;
        q.push({ r, c });
    }

    Initialize();

    int ans = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newY = cur.first + dy[i];
            int newX = cur.second + dx[i];

            if (grid[newY][newX] == -1) ++ans;
        }
    }
    cout << ans;

    return 0;
}