#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
int n;
ll h[MaxN+5], r[MaxN+5], l[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
}

ll Solution() {
    ll ans = 0;
    for (int i=n; i>=1; i--)
        r[i] = max(r[i+1], h[i]);
    for (int i=1; i<=n; i++)
        l[i] = max(l[i-1], h[i]);
    for (int i=1; i<=n; i++)
        ans += min(r[i], l[i]) - h[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
