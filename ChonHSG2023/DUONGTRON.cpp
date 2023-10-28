#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n;
pii a[MaxN+5];
map<ll, int> cnt;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
}

int Solution() {
    for (int i=1; i<=n; i++) {
        ll tmp = (a[i].first * a[i].first) + (a[i].second * a[i].second);
        cnt[tmp]++;
    }
    int res = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        res = max(res, (*it).second);
        //cout << (*it).first << ' ' << (*it).second << '\n';
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DUONGTRON.INP", "r", stdin);
    freopen("DUONGTRON.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
