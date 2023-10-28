#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400005
using namespace std;
typedef long double ld;
int m, n, DigCnt[MaxN+5];

void MakeDigCnt() {
    ld CurSumLog = 0;
    DigCnt[0] = 1;
    for (int i=1; i<=MaxN; i++) {
        CurSumLog += log10(i);
        DigCnt[i] = int(CurSumLog) + 1;
    }
}

void Solve() {
    int ansLow = -1, ansHigh = -1, i = 0;
    while ((ansLow == -1) || (ansHigh == -1)) {
        if ((DigCnt[i] >= m) && (ansLow == -1))
            ansLow = i;
        if ((DigCnt[i] > n) && (ansHigh == -1))
            ansHigh = i-1;
        i++;
    }
    if ((ansLow == -1) || (ansHigh == -1) || (ansLow > ansHigh))
        cout << "-1";
    else
        cout << ansLow << ' ' << ansHigh;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeDigCnt();
    cin >> m >> n;
    Solve();
    return 0;
}
