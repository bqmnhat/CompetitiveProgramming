#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n;
ll x, y, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    ll ans = 0, tmp = 0;
    bool IsInRange = false;
    int l = 1, r = 1, AnsL, AnsR;
    while (r <= n) {
        if ((a[r] < x) || (tmp + a[r] < 0LL)) {
            l = r + 1;
            r++;
            tmp = 0;
            IsInRange = false;
        }
        else {
            tmp += a[r];
            IsInRange |= ((a[r] >= x) && (a[r] <= y));
            if ((IsInRange) && (tmp > ans)){
                ans = tmp;
                AnsL = l;
                AnsR = r;
            }
            r++;
        }
    }
    cout << ans << '\n';
    cout << AnsL << ' ' << AnsR;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    ReadData();
    Solve();
    return 0;
}
