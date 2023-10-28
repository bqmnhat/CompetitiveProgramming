#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, dp[10001], m[10001];
pii B[10001];
vector<int> LIS;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> B[i].first >> B[i].second;
}

void Init() {
    for (int i=1; i<=n; i++)
        dp[i] = 1;
    LIS.clear();
}

int Solution() {
    sort(B+1, B+1+n);
    for (int i=1; i<=n; i++)
        m[i] = B[i].second;
    for (int i=1; i<=n; i++) {
        int j = upper_bound(LIS.begin(), LIS.end(), m[i]) - LIS.begin();
        dp[i] = j + 1;
        if (j == LIS.size())
            LIS.push_back(m[i]);
        else
            LIS[j] = m[i];
    }
    return LIS.size();
}

void Solve() {
    cin >> n;
    while (n != 0) {
        ReadData();
        Init();
        cout << Solution() << '\n';
        cin >> n;
    }
    cout << '*';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
