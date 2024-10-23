#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(2 * n);

    int curPoint = 0;
    for(int i = 0; i < n; ++i)
    {
        int length;
        char dir;

        cin >> length >> dir;
        if(dir == 'R')
        {
            v[2 * i] = {curPoint, +1};
            curPoint += length;
            v[2 * i  + 1] = { curPoint, -1};
        }
        else
        {
            v[2 * i + 1] = {curPoint, -1};
            curPoint -= length;
            v[2 * i] = {curPoint, +1};
        }
    }

    sort(v.begin(), v.end());

    curPoint = v.front().first - 1;
    int ans = 0;
    int nOverlap = 0;
    for(const pair<int, int> info : v)
    {
        if(info.first != curPoint)
        {
            if(k <= nOverlap)
            {
                ans += (info.first - curPoint);
            }
            curPoint = info.first;
        }

        nOverlap += info.second;
    }
    cout << ans;
    return 0;
}