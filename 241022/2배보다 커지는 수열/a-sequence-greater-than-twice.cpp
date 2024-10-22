#include <iostream>
using namespace std;
int dp[10][2001]; // n + 1개를 골랐으며, 마지막에 m + 1을 고른 경우의 수
const int MOD = 1000000007;
int main() {
    int n, m;
    cin >> n >> m;

    // initialize
    // 1개를 골랐을 때의 경우의 수
    for (int i = 1; i <= m; ++i)
        dp[0][i] = 1;


    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 1; k <= j / 2; ++k)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans += dp[n - 1][i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}