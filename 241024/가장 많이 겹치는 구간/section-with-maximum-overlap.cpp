#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n * 2);
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        v.push_back({l, +1});
        v.push_back({r, -1});
    }

    sort(v.begin(), v.end());

    int ans = -1;
    for(int i = 1; i <= 200000; ++i)
    {
        int temp = 0;
        for(int j = 0; j < v.size(); ++j)
        {
            if(v[j].first > i) break;
            temp += v[j].second;
        }
        ans = max(ans, temp);
    }
    cout << ans;
    return 0;
}