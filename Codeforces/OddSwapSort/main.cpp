#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001], e[100001], o[100001], le = 0, lo = 0;

void ReadData() {
    le = lo = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0)
            e[++le] = a[i];
        else
            o[++lo] = a[i];
    }
}

void SolveTestCase() {
    for (int i=1; i<=le; i++) {
        if (e[i] < e[i-1]) {
            cout << "No" << '\n';
            return;
        }
    }
    for (int j=1; j<=lo; j++) {
        if (o[j] < o[j-1]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
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
