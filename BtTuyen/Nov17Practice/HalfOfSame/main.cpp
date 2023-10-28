#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[41], MinAi = 1e9;
bool Solvable = false;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if ((i != 1) && (a[i] != a[1]))
            Solvable = true;
        MinAi = min(MinAi, a[i]);
    }
}

int GCD(int a, int b) {
    int tmp = 0;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

void SolveTestCases() {
    if (!Solvable) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for (int i=1; i<=n; i++)
        ans = GCD(ans, a[i] - MinAi);
    cout << ans << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        MinAi = 1e9;
        Solvable = false;
        if (n == 1)
            Solvable = true;
        ReadData();
        SolveTestCases();
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
