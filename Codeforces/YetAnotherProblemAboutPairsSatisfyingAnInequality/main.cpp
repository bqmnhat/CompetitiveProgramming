#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n, a[MaxN+1];
vector<int> tmp;

void ReadData() {
    tmp.clear();
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] < i)
            tmp.push_back(a[i]);
    }
}

ll Solution() {
    ReadData();
    sort(tmp.begin(), tmp.end());
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] >= i)
            continue;
        int j = upper_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
        ans = ans + 1LL*(tmp.size() - j);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() << '\n';
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
