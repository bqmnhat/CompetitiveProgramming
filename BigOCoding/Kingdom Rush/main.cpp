#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
struct Round {
    int lv1, lv2;
} r[1001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> r[i].lv1 >> r[i].lv2;
}

bool CmpLevel(Round a, Round b) {
    return (a.lv2 < b.lv2);
}

void SolveTestCase() {
    ans = 0;
    int s = 0, CurLev = 1;
    sort(r+1, r+1+n, CmpLevel);
    while (CurLev <= n) {
        if (r[CurLev].lv2 <= s) {
            if (r[CurLev].lv1 == -1)
                s++;
            else
                s += 2;
            ans++;
            CurLev++;
            continue;
        }
        int j;
        for (j = n; j>=CurLev; j--) {
            if ((r[j].lv1 != -1) && (r[j].lv1 <= s))
                break;
        }
        if (j == CurLev-1) {
            cout << "Too bad\n";
            return;
        }
        r[j].lv1 = -1;
        ans++;
        s++;
    }
    cout << ans << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ans = 0;
        ReadData();
        cout << "Case #" << i << ": ";
        SolveTestCase();
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
