#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll SumXor = 0, a[MaxN+1];

void Solve() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        SumXor ^= a[i];
    }
    if (SumXor == 0)
        cout << "Bob";
    else
        cout << "Alice";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
