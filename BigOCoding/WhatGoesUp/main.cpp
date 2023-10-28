#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[100001];
ll a[100001];
vector<ll> LIS;

void ReadData() {
    n = 1;
    while (cin >> a[n])
        n++;
    n--;
}

void Init() {
    LIS.clear();
    for (int i=0; i<=n; i++)
        dp[i] = 1;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        int j = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        dp[i] = j + 1;
        if (j == LIS.size())
            LIS.push_back(a[i]);
        else
            LIS[j] = a[i];
    }
    cout << LIS.size() << '\n';
    int tmp;
    for (int i=n; i>=1; i--) {
        if (dp[i] == LIS.size()) {
            tmp = i;
            break;
        }
    }
    vector<ll> res;
    res.push_back(tmp);
    tmp--;
    while (tmp > 0) {
        if ((a[tmp] < a[res.back()]) && (dp[res.back()] == dp[tmp] + 1))
            res.push_back(tmp);
        tmp--;
    }
    cout << "-\n";
    while (res.size() > 0) {
        cout << a[res.back()] << '\n';
        res.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    Init();
    Solve();
    return 0;
}
