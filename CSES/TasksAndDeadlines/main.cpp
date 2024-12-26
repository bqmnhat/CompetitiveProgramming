#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
pii Jobs[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> Jobs[i].first >> Jobs[i].second;
}

ll Solution() {
    ll ans = 0;
    sort(Jobs+1, Jobs+1+n);
    ll CurTime = 0;
    for (int i=1; i<=n; i++) {
        CurTime += Jobs[i].first;
        ans += (Jobs[i].second - CurTime);
    }
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
