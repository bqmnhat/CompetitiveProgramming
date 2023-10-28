#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair <char, int> Ipair;
int t, n;
string s;
Ipair a[200001];

void ReadAndSplitData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].second;
    cin >> s;
    for (int i=0; i<s.length(); i++)
        a[i+1].first = s[i];
}

void SolveTestCase() {
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        if ((a[i].first == 'B')&& (a[i].second < i)) {
            cout << "NO";
            return;
        }
        if ((a[i].first == 'R') && (a[i].second > i)) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadAndSplitData();
        SolveTestCase();
        cout << '\n';
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
