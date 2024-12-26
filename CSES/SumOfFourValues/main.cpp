#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int n;
ll x, a[MaxN+5];
multimap<ll, pii> ma;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            ll val = a[i] + a[j];
            ll RemainVal = x - val;
            auto it = ma.equal_range(RemainVal);
            for (auto itr = it.first; itr != it.second; itr++) {
                ll Key = itr->first;
                pii Value = itr->second;
                if ((Value.first == i) || (Value.first == j)
                || (Value.second == i) || (Value.second == j))
                    continue;
                cout << i << ' ' << j << ' ' << Value.first << ' ' << Value.second;
                return;
            }
            ma.insert({val, pii(i, j)});
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    Solve();
    return 0;
}
