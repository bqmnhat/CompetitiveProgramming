#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int n;
ll x;
vector<pii> a;

void ReadData() {
    a.push_back(pii(0, 0));
    for (int i=1; i<=n; i++) {
        int val;
        cin >> val;
        a.push_back(pii(val, i));
    }
}

int FindId(int lo, int hi, ll val) {
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (a[mid].first == val)
            return mid;
        else if (a[mid].first < val)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

void Solve() {
    sort(a.begin(), a.end());
    int id1 = -1, id2 = -1, id3 = -1;
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll valToFind = x - a[i].first - a[j].first;
            int id = FindId(j+1, n, valToFind);
            if (id == -1)
                continue;
            id1 = a[i].second;
            id2 = a[j].second;
            id3 = a[id].second;
        }
    }
    if (id1 == -1) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << id1 << ' ' << id2 << ' ' << id3;
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
