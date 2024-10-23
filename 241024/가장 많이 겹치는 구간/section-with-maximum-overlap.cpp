#include <iostream>
using namespace std;
int check[200001];
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        ++check[l];
        --check[r];
    }

    int ans = -1;
    int nOverlap = 0;
    for(int i = 1; i <= 200000; ++i)
    {
        nOverlap += check[i];
        ans = max(ans, nOverlap);
    }
    cout << ans;
    return 0;
}