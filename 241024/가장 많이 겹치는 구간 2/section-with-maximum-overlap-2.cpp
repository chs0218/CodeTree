#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(2 * n);
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;

        v[2 * i] = {l, +1};
        v[2 * i + 1] = {r, -1};
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int cur = 0;
    for(const pair<int, int>& info : v)
    {
        cur += info.second;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}