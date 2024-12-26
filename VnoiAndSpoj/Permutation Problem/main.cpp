#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
int t, n;
ll p[MaxN+5], a[MaxN+5], b[MaxN+5], cnt[MaxN+5], last[MaxN+5], res[MaxN+5];
vector<ll> vecA[MaxN+5], vecB[MaxN+5];

void Init() {
    for (int i=1; i<=n; i++) {
        last[i] = -1;
        vecA[i].clear();
        vecB[i].clear();
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        ll g = __gcd(p[i], (ll)i);
        a[i] = p[i]/g;
        b[i] = i/g;
        vecA[a[i]].push_back(i);
        vecB[b[i]].push_back(i);
    }
}

ll Solution() {
    ll ans = 0;
    for (ll x = 1; x<=n; x++) {
        for (int i: vecB[x])
            cnt[a[i]]++;
        for (int y = x; y<=n; y+=x) {
            for (int i: vecA[y]) {
                if (last[b[i]] != x) {
                    res[b[i]] = 0;
                    for (int j=b[i]; j<=n; j+=b[i])
                        res[b[i]] += cnt[j];
                    last[b[i]] = x;
                }
                ans += res[b[i]];
            }
        }
        for (int i: vecB[x])
            cnt[a[i]]--;
    }
    for (int i=1; i<=n; i++)
        if (b[i] == 1)
            ans--;
    ans /= 2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        Init();
        ReadData();
        cout << Solution() << '\n';
    }
    return 0;
}
