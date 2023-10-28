#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[1001], T;
ll a[1001];
vector<ll> LIS;

void Init() {
    for (int i=1; i<=n; i++)
        dp[i] = 1;
    LIS.clear();
}

void ReadData() {
    string s;
    int i = 0;
    getline(cin, s);
    while (s != "") {
        i++;
        stringstream ss(s);
        ss >> a[i];
        s = "";
        getline(cin, s);
    }
    n = i;
}

void SolveTestCase() {
    for (int i=1; i<=n; i++) {
        int j = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        dp[i] = j + 1;
        if (j == LIS.size()) {
            LIS.push_back(a[i]);
        }
        else
            LIS[j] = a[i];
    }
    cout << "Max hits: " << LIS.size() << '\n';
    int tmp;
    for (int i=1; i<=n; i++)
        if (dp[i] == LIS.size()) {
            tmp = i;
            break;
        }
    vector<ll> res;
    res.push_back(tmp);
    tmp--;
    while (tmp > 0) {
        if ((a[tmp] < a[res.back()]) && (dp[res.back()] == dp[tmp] + 1))
            res.push_back(tmp);
        tmp--;
    }
    while (res.size() != 0) {
        cout << a[res.back()] << '\n';
        res.pop_back();
    }
}

void Solve() {
    for (int i=1; i<=T; i++) {
        ReadData();
        Init();
        SolveTestCase();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    cin.ignore();
    cin.ignore();
    Solve();
    return 0;
}
