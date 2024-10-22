#include <iostream>
using namespace std;

int coins[50][10];
int dp[50][1001];   // n명의 사람이 돈을 냈을 때, 합이 k가 되는 경우의 수
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        int nCoin;
        cin >> nCoin;
        for (int j = 0; j < nCoin; ++j)
        {
            cin >> coins[i][j];
        }
    }

    // Initialize
    // 첫번째 사람이 들고 있는 동전으로 초기화
    
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        // 동전 가격이 0이면 탐색 완료
        if (coins[0][i] == 0) break;
        dp[0][coins[0][i]] += 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (coins[i][j] == 0) break;
            dp[i][coins[i][j]] += 1;
        }

        for (int j = 1; j <= 1000; ++j)
        {
            dp[i][j] += dp[i - 1][j];
            for (int k = 0; k < 10; ++k)
            {
                if (coins[i][k] == 0) break;
                if (dp[i - 1][j] > 0 && j + coins[i][k] <= 1000)
                {
                    dp[i][j + coins[i][k]] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[n - 1][k] % 10007;
    return 0;
}