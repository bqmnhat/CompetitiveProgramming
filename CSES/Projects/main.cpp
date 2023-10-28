#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, ptr[2*MaxN+5];
struct Proj{
    int st, ed;
    ll w;
} a[MaxN+5];
unordered_map<int, int> m;
vector<int> ForSort;
vector<pii> FinProj[2*MaxN+5];
ll dp[2*MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].st >> a[i].ed >> a[i].w;
        ForSort.push_back(a[i].st);
        ForSort.push_back(a[i].ed);
    }
}

void Compress() {
    sort(ForSort.begin(), ForSort.end());
    int cnt = 0;
    for (int v: ForSort)
        m[v] = ++cnt;
    for (int i=1; i<=n; i++)
        FinProj[m[a[i].ed]].push_back(pii(a[i].w, m[a[i].st]));
}

ll Solution() {
    for (int i=1; i<=2*n; i++) {
        dp[i] = dp[i-1];
        for (pii tmp: FinProj[i])
            dp[i] = max(dp[i], dp[tmp.second-1] + tmp.first);
    }
    return dp[2*n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Compress();
    cout << Solution();
    return 0;
}
