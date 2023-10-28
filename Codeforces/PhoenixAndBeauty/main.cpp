#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,k,a[101],Distinct[101], ld = 0;
bool Exist[101];

void Init() {
    for (int i=1; i<=100; i++)
        Exist[i] = false;
    ld = 0;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (!Exist[a[i]]) {
            Exist[a[i]] = true;
            ld++;
            Distinct[ld] = a[i];
        }
    }
}

void SolveTestCase() {
    if (ld > k) {
        cout << "-1\n";
        return;
    }
    cout << n*k << '\n';
    for (int i=1; i<=n; i++) {
        for (int i=1; i<=ld; i++)
            cout << Distinct[i] << ' ';
        for (int i=1; i<=k - ld; i++)
            cout << 1 << ' ';
    }
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        Init();
        ReadData();
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
