#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, q, cnt[MaxN+1];

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> q;
        int p, x;
        memset(cnt, 0, sizeof(cnt));
        bool CanSolve = true;
        for (int i=1; i<=q; i++) {
            cin >> p >> x;
            if (p == 1)
                cnt[x]++;
            else {
                if (cnt[x] == 0) {
                    if (cnt[0] == 0)
                        CanSolve = false;
                    else
                        cnt[0]--;
                }
                else
                    cnt[x]--;
            }
        }
        if (CanSolve)
            cout << "YES\n";
        else
            cout << "NO\n";
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
