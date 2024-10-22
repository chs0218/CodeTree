#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int nGrid = 0;
char grid[100][100];
bool bVisisted[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool bIsValidCoord(int i, int j)
{
    if (i < 0) return false;
    if (j < 0) return false;
    if (i >= nGrid) return false;
    if (j >= nGrid) return false;
    return true;
}
void ColorSectionRGB(int y, int x)
{
    char curColor = grid[y][x];
    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (bIsValidCoord(nextY, nextX) && !bVisisted[nextY][nextX])
        {
            char nextColor = grid[nextY][nextX];
            if (nextColor == curColor)
            {
                bVisisted[nextY][nextX] = true;
                ColorSectionRGB(nextY, nextX);
            }
        }
    }
}
void ColorSectionYB(int y, int x)
{
    char curColor = grid[y][x];
    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        char nextColor = grid[nextY][nextX];

        if (bIsValidCoord(nextY, nextX) && !bVisisted[nextY][nextX])
        {
            char nextColor = grid[nextY][nextX];
            if (curColor == 'B' && nextColor == 'B')
            {
                bVisisted[nextY][nextX] = true;
                ColorSectionYB(nextY, nextX);
            }
            if ((curColor == 'R' || curColor == 'G') && (nextColor == 'R' || nextColor == 'G'))
            {
                bVisisted[nextY][nextX] = true;
                ColorSectionYB(nextY, nextX);
            }
        }
    }
}
int main() {

    // 입력 받기
    cin >> nGrid;
    for (int i = 0; i < nGrid; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < nGrid; ++j)
        {
            grid[i][j] = str[j];
        }
    }

    int ans[2] = { 0, 0 };
    memset(bVisisted, false, sizeof(bVisisted));
    for (int i = 0; i < nGrid; ++i)
    {
        for (int j = 0; j < nGrid; ++j)
        {
            if (!bVisisted[i][j])
            {
                ans[0] += 1;
                bVisisted[i][j] = true;
                ColorSectionRGB(i, j);
            }
        }
    }

    memset(bVisisted, false, sizeof(bVisisted));
    for (int i = 0; i < nGrid; ++i)
    {
        for (int j = 0; j < nGrid; ++j)
        {
            if (!bVisisted[i][j])
            {
                ans[1] += 1;
                bVisisted[i][j] = true;
                ColorSectionYB(i, j);
            }
        }
    }

    cout << ans[0] << " " << ans[1];
    return 0;
}