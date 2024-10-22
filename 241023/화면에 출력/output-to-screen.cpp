#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
bool bVisited[1001][1001];
int main() {
    int s;
    cin >> s;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    bVisited[1][0] = true;
    pq.push({ 0, 1, 0 });

    int ans = 1e9;
    while (!pq.empty())
    {
        tuple<int, int, int> cur = pq.top();
        pq.pop();

        int nValue = get<0>(cur);
        int nCharacter = get<1>(cur);
        int nClipBoard = get<2>(cur);

        if (s == nCharacter)
        {
            ans = nValue;
            break;
        }

        if (3 < nCharacter && !bVisited[nCharacter - 1][nClipBoard])
        {
            bVisited[nCharacter - 1][nClipBoard] = true;
            pq.push({ nValue + 1, nCharacter - 1, nClipBoard });
        }

        if(nCharacter < s && !bVisited[nCharacter][nCharacter])
        {
            bVisited[nCharacter][nCharacter] = true;
            pq.push({ nValue + 1, nCharacter, nCharacter });
        }

        if (nCharacter < s && nClipBoard != 0 && 
            nCharacter + nClipBoard <= 1000 && !bVisited[nCharacter + nClipBoard][nClipBoard])
        {
            bVisited[nCharacter + nClipBoard][nClipBoard] = true;
            pq.push({ nValue + 1, nCharacter + nClipBoard, nClipBoard });
        }
    }
    cout << ans;
    return 0;
}