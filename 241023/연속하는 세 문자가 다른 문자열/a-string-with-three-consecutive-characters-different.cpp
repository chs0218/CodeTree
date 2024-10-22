#include <iostream>
using namespace std;
int n;
int nCharacter[6];
int MakeWord(int nLastLastCharacter, int nLastCharacter)
{
    bool bUsedAllcharacter = true;
    for(int i = 1; i <= n; ++i)
    {
        if(nCharacter[i] > 0) 
        {
            bUsedAllcharacter = false;
            break;
        }
    }
    if(bUsedAllcharacter) return 1;

    int ret = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(nCharacter[i] > 0 && i != nLastCharacter && i != nLastLastCharacter)
        {
            nCharacter[i] -= 1;
            ret += MakeWord(nLastCharacter, i);
            nCharacter[i] += 1;
        }
    }
    return ret;
}
int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> nCharacter[i];
    }

    int ans = MakeWord(0, 0);
    cout << ans;
    return 0;
}