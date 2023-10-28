#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, m, k;
vector<pii> ansSeq;
ll s, a[MaxN+1], b[MaxN+1];
pii Gadgets[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    for (int i=1; i<=m; i++)
        cin >> Gadgets[i].first >> Gadgets[i].second;
}

bool Check(int MaxDays, vector<pii>& ansSeq) {
    ll MinDollar = 1e18, MinEuro = 1e18;
    int MinDollarDay, MinEuroDay;
    for (int i=1; i<=MaxDays; i++) {
        if (a[i] < MinDollar) {
            MinDollar = a[i];
            MinDollarDay = i;
        }
        if (b[i] < MinEuro) {
            MinEuro = b[i];
            MinEuroDay = i;
        }
    }
    vector<pii> Price;
    Price.clear();
    for (int i=1; i<=m; i++) {
        ll tmp;
        if (Gadgets[i].first == 1)
            tmp = Gadgets[i].second * MinDollar;
        else
            tmp = Gadgets[i].second * MinEuro;
        Price.push_back(pii(tmp, i));
    }
    sort(Price.begin(), Price.end());
    ll Cost = 0;
    for (int i=0; i<k; i++)
        Cost += Price[i].first;
    if (Cost <= s) {
        ansSeq.clear();
        for (int i=0; i<k; i++) {
            if (Gadgets[Price[i].second].first == 1)
                ansSeq.push_back(pii(Price[i].second, MinDollarDay));
            else
                ansSeq.push_back(pii(Price[i].second, MinEuroDay));
        }
        return true;
    }
    return false;
}

void Solve() {
    int lo = 1, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (Check(mid, ansSeq)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << '\n';
    if (ans != -1)
        for (pii x: ansSeq)
            cout << x.first << ' ' << x.second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s;
    ReadData();
    Solve();
    return 0;
}
