#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dpInc[10001], dpDec[10001];
ll a[10001];
vector<ll> LIS, LDS;

void Init() {
    LIS.clear();
    LDS.clear();
    for (int i=1; i<=n; i++)
        dpInc[i] = dpDec[i] = 1;
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void FindLIS(ll aa[], int dp[], vector<ll>& LISx) {
    for (int i=1; i<=n; i++) {
        int j = lower_bound(LISx.begin(), LISx.end(), aa[i]) - LISx.begin();
        dp[i] = j + 1;
        if (j == LISx.size())
            LISx.push_back(aa[i]);
        else
            LISx[j] = aa[i];
    }
}

int Solution() {
    int ans = 1;
    FindLIS(a, dpInc, LIS);
    reverse(a+1, a+1+n);
    FindLIS(a, dpDec, LDS);
    reverse(dpDec+1, dpDec+1+n);
    for (int i=1; i<=n; i++)
        ans = max(ans, min(dpInc[i], dpDec[i])*2 - 1);
    return ans;
}

void Solve() {
    while (cin >> n) {
        ReadData();
        Init();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
