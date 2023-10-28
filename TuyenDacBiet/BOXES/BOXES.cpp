#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
pii a[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        int MinAns = 1e9;
        for (int j=1; j<=n; j++) {
            int TmpAns = 0;
            if (i == j)
                continue;
            if (a[j].first < a[i].first)
                TmpAns += (a[i].first - a[j].first);
            if (a[j].second < a[i].second)
                TmpAns += (a[i].second - a[j].second);
            MinAns = min(MinAns, TmpAns);
        }
        cout << MinAns << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BOXES.INP", "r", stdin);
    freopen("BOXES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
