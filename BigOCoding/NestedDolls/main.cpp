#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int t, n, h[20001];
pii D[20001];
vector<int> LIS;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> D[i].first >> D[i].second;
}

bool CmpPii(pii a, pii b) {
    return ((a.first < b.first) || ((a.first == b.first) && (a.second > b.second)));
}

int Solution() {
    LIS.clear();
    sort(D+1, D+1+n, CmpPii);
    for (int i=1; i<=n; i++)
        h[i] = D[i].second;
    LIS.push_back(h[1]);
    for (int i=2; i<=n; i++) {
        int j = LIS.size() - 1;
        while ((j >= 0) && (LIS[j] < h[i])) j--;
        if (j == LIS.size() - 1)
            LIS.push_back(h[i]);
        LIS[j+1] = max(LIS[j+1], h[i]);
    }
    return LIS.size();
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
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
