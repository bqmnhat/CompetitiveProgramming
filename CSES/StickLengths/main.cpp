#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll p[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

ll Solution() {
    sort(p+1, p+1+n);
    ll Med;
    if (n&1)
        Med = p[(n>>1) + 1];
    else
        Med = ((p[(n >> 1)] + p[(n >> 1) + 1]) >> 1LL);
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans += abs(p[i] - Med);
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
