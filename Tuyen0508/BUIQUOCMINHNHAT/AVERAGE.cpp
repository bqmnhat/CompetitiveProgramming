#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1], k;
map<ll, ll> PrefFreq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll ans = 0, CurPref = 0;
    for (int i=1; i<=n; i++) {
        CurPref += (a[i] - k);
        if (CurPref == 0)
            ans++;
        if (PrefFreq.find(CurPref) != PrefFreq.end())
            ans += PrefFreq[CurPref];
        PrefFreq[CurPref]++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("AVERAGE.INP", "r", stdin);
    freopen("AVERAGE.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
