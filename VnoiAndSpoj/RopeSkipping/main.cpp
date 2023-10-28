#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000000
using namespace std;
typedef long long ll;
int n, c[MaxN+1];
ll cnt[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        cnt[c[i]]++;
    }
}

void Solve() {
    for (int i=1; i <= MaxN; i++)
        for (int j=2; i*j<=MaxN; j++)
            cnt[i] += cnt[i*j];
    for (int i=1; i<=n; i++)
        cout << (cnt[2*c[i]]*(cnt[2*c[i]] - 1LL))/2 << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
