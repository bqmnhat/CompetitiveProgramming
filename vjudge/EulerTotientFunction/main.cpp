#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int t, n, phi[MaxN+5];

void CalPhi() {
    for (int i=0; i<=MaxN; i++)
        phi[i] = i;
    for (int i=2; i<=MaxN; i++)
        if (phi[i] == i)
            for (int j=i; j<=MaxN; j += i)
                phi[j] -= phi[j]/i;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << phi[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalPhi();
    cin >> t;
    Solve();
    return 0;
}
