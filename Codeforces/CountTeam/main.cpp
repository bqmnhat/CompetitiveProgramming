#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,m,q;
long long l,r,a[100001], b[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=m; i++)
        cin >> b[i];
}

long long NumOfPairs() {
    long long ans = 0;
    int i = m, j = m;
    for (int x=1; x<=n; x++) {
        while ((i-1 >= 1) && (a[x] * b[i-1] >= l))
            i--;
        while ((j-1 >= 1) && (a[x] * b[j] > r))
            j--;
        if (((a[x] * b[i]) >= l) && ((a[x] * b[j]) <= r))
            ans += (j-i+1);
    }
    return ans;
}

void Solve() {
    while (t--) {
        cin >> n >> m;
        ReadData();
        sort(b+1, b+1+m);
        sort(a+1, a+1+n);
        cin >> q;
        while (q--) {
            cin >> l >> r;
            cout << NumOfPairs() << '\n';
        }
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
