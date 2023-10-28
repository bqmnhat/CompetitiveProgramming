#include <iostream>
#include <bits/stdc++.h>
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
using namespace std;
int n, LookUpTab[256] = {B6(0), B6(1), B6(1), B6(2)};
union {
    int a1;
    unsigned char a2[64];
} x;

void MakeLookUpTab() {
    for (int i = 0; i < 256; i++)
        LookUpTab[i] = (i & 1) + LookUpTab[i / 2];
}

int NumOfBitOnes() {
    int i = 0, ans = 0;;
    while (x.a2[i] != 0) {
        ans += LookUpTab[x.a2[i]];
        i++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeLookUpTab();
    cin >> x.a1;
    cout << NumOfBitOnes();
    return 0;
}
