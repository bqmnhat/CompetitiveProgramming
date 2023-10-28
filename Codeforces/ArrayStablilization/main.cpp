#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,d,a[1000002];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

int GCD(int a, int b) {
    int tmp;
    while (a != 0) {
        tmp = a;
        a = b%a;
        b = tmp;
    }
    return b;
}

void Solve() {
    int t = GCD(n,d);
    bool FoundZero = false;
    int ans = 0;
    for (int i=0; i<t; i++) {
        int j = i, x = 0, cnt = 0, pref = 0;
        FoundZero = false;
        while (cnt < (n/t)) {
            if (a[j] == 0) {
                FoundZero = true;
                x = 0;
            }
            else {
                x++;
                if (cnt == pref)
                    pref++;
            }
            ans = max(ans, x);
            j = (j + n - d)%n;
            cnt++;
        }
        if (cnt != pref)
            ans = max(ans, x + pref);
        else {
            FoundZero = false;
            break;
        }
    }
    if (!FoundZero) {
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}

void SolveTestCases() {
    for (int i=1; i<=t; i++) {
        cin >> n >> d;
        ReadData();
        Solve();
        for (int i = 0; i<=n; i++)
            a[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    SolveTestCases();
    return 0;
}
