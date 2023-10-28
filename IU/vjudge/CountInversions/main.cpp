#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int t, n, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll CountInversions(int lo, int hi) {
    int mid = (lo + hi)/2;
    if (lo == hi)
        return 0;
    ll ans = CountInversions(lo, mid) + CountInversions(mid+1, hi), i = 1, j = 1, id = lo-1;
    vector<int> a1, a2;
    a1.push_back(0);
    a2.push_back(0);
    for (int i=lo; i<=mid; i++)
        a1.push_back(a[i]);
    for (int j=mid+1; j<=hi; j++)
        a2.push_back(a[j]);
    while ((i < a1.size()) && (j < a2.size())) {
        id++;
        if (a1[i] <= a2[j]) {
            a[id] = a1[i];
            i++;
        }
        else {
            ans += (ll)a1.size() - i;
            a[id] = a2[j];
            j++;
        }
    }
    while (i < a1.size()) {
        id++;
        a[id] = a1[i];
        i++;
    }
    while (j < a2.size()) {
        id++;
        a[id] = a2[j];
        j++;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << CountInversions(1, n) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
