#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxK 100000
using namespace std;
int n, k, a[MaxN+1];
bool dp[MaxK+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    for (int i=0; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            if ((i + a[j] <= k) && (!dp[i]))
                dp[i + a[j]] = true;
        }
    }
    if (dp[k])
        cout << "First";
    else
        cout << "Second";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
