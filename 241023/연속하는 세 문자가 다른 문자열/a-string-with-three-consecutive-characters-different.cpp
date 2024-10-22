#include <iostream>
#include <memory.h>

#define MAX_N 5
#define MAX_M 10

using namespace std;

// 변수 선언
int n;
int freq[MAX_N];

// dp[s1, s2, s3, s4, s5, c1, c2] : 
// 각 문자가 s1, .., s5개 남았고 최근 연속한 2개의 문자 번호가 순서대로 c1, c2라 했을 때
// 가능한 서로 다른 가짓수
long long dp[MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_M + 1][MAX_N + 1][MAX_N + 1];

long long Counting(int c1, int c2) {
    long long &ret = dp[freq[0]][freq[1]][freq[2]][freq[3]][freq[4]][c1][c2];
    if(ret != -1)
        return ret;
    
    // 초기조건은 freq 값이 전부 0인 경우입니다.
    if(freq[0] + freq[1] + freq[2] + freq[3] + freq[4] == 0)
        return 1;
    
    ret = 0;
    for(int i = 0; i < n; i++)
        if(freq[i] > 0 && i != c1 && i != c2) {
            freq[i]--;
            ret += Counting(c2, i);
            freq[i]++;
        }
    
    return ret;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> freq[i];

    // dp값을 -1로 초기화합니다.
    memset(dp, -1, sizeof(dp));
    
    cout << Counting(n, n);
    return 0;
}