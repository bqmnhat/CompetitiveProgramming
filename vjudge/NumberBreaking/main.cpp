#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t, n, d[MaxN+5];

void MakeD() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                d[i*j] = i;
}

void SolveTestCase() {
    map<int, int> mu;
    mu.clear();
    while (n>1) {
        int p = d[n];
        if (p == 0)
            p = n;
        mu[p]++;
        n /= p;
    }
    for (auto it=mu.begin(); it!=mu.end(); it++)
        cout << (*it).first << ' ';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << "Case " << i << ": ";
        SolveTestCase();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeD();
    cin >> t;
    Solve();
    return 0;
}
