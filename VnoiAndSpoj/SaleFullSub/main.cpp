#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxM 10
using namespace std;
typedef long long ll;
typedef pair<ll, int> pil;
int n, m, k;
ll a[MaxN+1][MaxM+1], pref[MaxN+1][MaxM+1], prefSumAll[MaxN+1];
pil SumAll[2*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            SumAll[i].first += a[i][j];
            SumAll[i].second = i;
            pref[i][j] = pref[i][j-1] + a[i][j];
        }
    }
}

bool CmpPil(pil a, pil b) {
    return (a.first > b.first);
}

ll Solution() {
    sort(SumAll+1, SumAll+1+n, CmpPil);
    int Full = k/m;
    int Partial = k%m;
    ll ans = 0;
    if (Partial == 0) {
        for (int i=1; i<=Full; i++)
            ans += SumAll[i].first;
    }
    else {
        for (int i=1; i<=n; i++)
            prefSumAll[i] = prefSumAll[i-1] + SumAll[i].first;
        for (int i=1; i<=n; i++) {
            ll tmp = 0;
            if (i <= Full)
                tmp = prefSumAll[Full + 1] - SumAll[i].first + pref[SumAll[i].second][Partial];
            else
                tmp = prefSumAll[Full] + pref[SumAll[i].second][Partial];
            ans = max(ans, tmp);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    cout << Solution();
    return 0;
}
