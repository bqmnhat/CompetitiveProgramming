#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,t, a[200001], sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

int MinK() {
    if (sum % n != 0)
        return -1;
    int c = sum/n;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] > c)
            ans++;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        sum = 0;
        ReadData();
        cout << MinK() << '\n';
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
