#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main() {
    int s;
    cin >> s;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({ 0, 1, 0 });

    int ans = 1e9;
    while (!pq.empty())
    {
        tuple<int, int, int> cur = pq.top();
        pq.pop();

        int nValue = get<0>(cur);
        int nCharacter = get<1>(cur);
        int nClipBoard = get<2>(cur);

        if (nCharacter < 1 && nClipBoard == 0)
            continue;

        if (nCharacter == s)
        {
            ans = nValue;
            break;
        }

        if (s > nCharacter)
        {
            if (nClipBoard != 0)
                pq.push({ nValue + 1, nCharacter + nClipBoard, nClipBoard });
            pq.push({ nValue + 1, nCharacter, nCharacter });
        }
        pq.push({ nValue + 1, nCharacter - 1, nClipBoard });
    }
    cout << ans;
    return 0;
}