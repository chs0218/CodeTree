#include <iostream>
using namespace std;
int coins[50][10];
int dp[50][1001];   // n명의 사람이 돈을 냈을 때, 합이 k가 되는 경우의 수
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; ++i)
    {
        int nCoin;
        cin >> nCoin;
        for(int j = 0; j < nCoin; ++j)
        {
            cin >> coins[i][j];
        }
    }

    // Initialize
    // 첫번째 사람이 들고 있는 동전으로 초기화

    for(int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;
    }

    for(int i = 0; i < 10; ++i)
    {
        // 동전 가격이 0이면 탐색 완료
        if(coins[0][i] == 0) break;
        dp[0][coins[0][i]] += 1;
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            // 동전 가격이 0이면 탐색 완료
            if(coins[i][j] == 0) break;
            for(int k = 0; k <= 1000; ++k)
            {
                // 경우의 수가 있으면
                if(dp[i - 1][k] > 0)
                {
                    if(k + coins[i][j] <= 1000)
                        dp[i][k + coins[i][j]] = (dp[i - 1][k] + 1) % 10007;
                    dp[i][k] = dp[i][k] + dp[i - 1][k];
                }
            }
        }
    }

    cout << dp[n - 1][k];
    return 0;
}