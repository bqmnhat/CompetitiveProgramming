#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t, sum, s[201];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        sum += s[i];
    }
}

double FindVotes(int i) {
    double lo = 0, hi = 1, ans;
    for (int loop = 0; loop < 100; loop++) {
        double m = (lo + hi)/2;
        double me = s[i] + sum*m;
        double rem = 1 - m;
        for (int j=1; j<=n; j++) {
            if (j == i)
                continue;
            double r = (me - s[j])/sum;
            rem = rem - max(0.0, r);
        }
        if (rem <= 0)
            ans = hi = m;
        else
            lo = m;
    }
    return (ans*100.00);
}

void SolveTestCases() {
    for (int i=1; i<=n; i++)
        cout << fixed << setprecision(6) << FindVotes(i) << ' ';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        sum = 0;
        ReadData();
        cout << "Case #" << i << ": ";
        SolveTestCases();
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
