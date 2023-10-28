#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
int t, n, a[MaxN+1];
string s;
char Relate[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> s;
}

void Solve() {
    for (int i=1; i<=MaxN; i++)
        Relate[i] = '#';
    for (int i=0; i<n; i++) {
        if (Relate[a[i+1]] == '#')
            Relate[a[i+1]] = s[i];
        else if (Relate[a[i+1]] != s[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        Solve();
    }
    return 0;
}
