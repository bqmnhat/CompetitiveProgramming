#include <iostream>
#include <bits/stdc++.h>
#define MaxN 26
using namespace std;
typedef long long ll;
int n;
ll SC[MaxN+1], C[MaxN+1];

void CalSC() {
    SC[1] = SC[2] = 1;
    for (ll i=3; i<=MaxN; i++)
        SC[i] = ((3*(2*i - 3)*SC[i-1]) - ((i - 3) * SC[i-2]))/i;
}

void CalC() {
    C[0] = 1;
    for (ll i=0; i<=MaxN; i++)
        C[i+1] = (C[i]*(4*i + 2))/(i+2);
}

void Solve() {
    while (cin >> n)
        cout << SC[n] - C[n-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalC();
    CalSC();
    Solve();
    return 0;
}
