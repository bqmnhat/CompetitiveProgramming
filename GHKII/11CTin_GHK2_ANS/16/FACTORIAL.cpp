#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
#define MaxL 400000
using namespace std;
typedef long double ld;
typedef long long ll;
int m, n;
ll Length[MaxL+5];

void MakeLength(int n) {
    ld tmpSum = 0;
    Length[0] = 1;
    for (int i=1; i<=n; i++) {
        tmpSum += log10(i);
        Length[i] = ll(tmpSum) + 1LL;
    }
}

void Solve() {
    int a = -1, b = -1, i = 0;
    while ((a == -1) || (b == -1)) {
        if ((Length[i] >= m) && (a == -1))
            a = i;
        if ((Length[i] > n) && (b == -1))
            b = i-1;
        i++;
    }
    if ((a == -1) || (b == -1))
        cout << "15 14";
    else
        cout << a << ' ' << b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FACTORIAL.INP", "r", stdin);
    freopen("FACTORIAL.OUT", "w", stdout);
    MakeLength(MaxL);
    cin >> m >> n;
    Solve();
    return 0;
}
