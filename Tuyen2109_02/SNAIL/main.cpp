#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
ll H, p[MaxN+1];
int n;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> p[i];
}

void Solve() {
    ll CycleLen = 0, MaxLen = 0, CurH = 0;
    for (int i=0; i<n; i++) {
        CycleLen += p[i];
        CurH = max(CurH + p[i], 0LL);
        if (CurH >= H) {
            cout << 0 << ' ' << i;
            return;
        }
        MaxLen = max(MaxLen, CycleLen);
    }
    if (CycleLen <= 0) {
        cout << "-1 -1";
        return;
    }
    ll D = max(0LL, ((H - CurH - MaxLen - 1LL)/CycleLen)- 2LL);
    CurH += D*CycleLen;
    int P = -1;
    while (CurH < H) {
        P = (P + 1)%n;
        CurH += p[P];
        if (P == 0)
            D++;
    }
    cout << D << ' ' << P;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> n;
    ReadData();
    Solve();
    return 0;
}
