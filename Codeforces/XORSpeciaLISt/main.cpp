#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool Splitable() {
    bool flag = true;
    for (int i=1; i<n; i++) {
        flag = (flag & (a[i] < a[i+1]));
    }
    if ((n%2 == 0) || (!flag))
        return true;
    else
        return false;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        if (Splitable())
            cout << "YES";
        else
            cout << "NO";
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
