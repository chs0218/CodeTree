#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int r, c;
    int minR, minC, maxR, maxC;

    cin >> minR >> minC;
    maxR = minR;
    maxC = minC;
    for(int i = 0; i < n; ++i)
    {
        cin >> r >> c;
        maxR = max(maxR, r);
        minR = min(minR, r);
        maxC = max(maxC, c);
        minC = min(minC, c);
    }

    int width = maxC - (minC - 1);
    int height = maxR - (minR - 1);

    cout << width * 2 + height * 2;
    return 0;
}