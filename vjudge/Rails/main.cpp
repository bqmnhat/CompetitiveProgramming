#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int a[MaxN+1], n;
vector<int> stk;

int SolveSingle() {
    stk.clear();
    string s;
    getline(cin, s);
    if (s == "0")
        return -1;
    stringstream ss(s);
    for (int i=1; i<=n; i++)
        ss >> a[i];
    int cnt = 1;
    for (int i=1; i<=n; i++) {
        while ((!stk.empty()) && (cnt <= n) && (stk.back() == a[cnt])) {
            cnt++;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    while ((!stk.empty()) && (cnt <= n) && (stk.back() == a[cnt])) {
        cnt++;
        stk.pop_back();
    }
    if (cnt <= n)
        return 0;
    return 1;
}

void SolveTestCase() {
    int ans = SolveSingle(), cnt = 0;
    while (ans != -1) {
        if (cnt > 0)
            cout << '\n';
        if (ans == 0)
            cout << "No";
        else
            cout << "Yes";
        cnt++;
        ans = SolveSingle();
    }
}

void Solve() {
    int cnt = 0;
    while ((cin >> n) && (n != 0)) {
        cin.ignore();
        SolveTestCase();
        cnt++;
        cout << "\n\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("Rails.INP", "r", stdin);
    //freopen("Rails.OUT", "w", stdout);
    Solve();
    return 0;
}
