#include <iostream>
#include <bits/stdc++.h>
#define MaxN 9
using namespace std;
int t, m, PowOf10[MaxN+1];

void MakePow10() {
    PowOf10[0] = 1;
    for (int i=1; i<=MaxN; i++)
        PowOf10[i] = PowOf10[i-1]*10;
}

int CntDigsMinus1(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt++;
        x/=10;
    }
    cnt--;
    return cnt;
}

void Solve() {
    MakePow10();
    for (int i=1; i<=t; i++) {
        cin >> m;
        int tmp = CntDigsMinus1(m);
        int ans = m - PowOf10[tmp];
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
