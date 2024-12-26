#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int t, n, k;
unordered_map<int, int> ma;
vector<pii> a;

void ReadData() {
    ma.clear();
    for (int i=1; i<=k; i++) {
        int bi, ci;
        cin >> bi >> ci;
        ma[bi] += ci;
    }
}

void PushIntoVector() {
    a.clear();
    for (auto itr = ma.begin(); itr != ma.end(); itr++)
        a.push_back(pii(itr->second, itr->first));
    sort(a.begin(), a.end(), greater<pii>());
}

int Solution() {
    int ans = 0;
    for (int i = 0; i < a.size() && i < n; i++)
        ans += a[i].first;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ReadData();
        PushIntoVector();
        cout << Solution() << '\n';
    }
    return 0;
}
