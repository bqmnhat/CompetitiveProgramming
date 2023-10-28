#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[200001], t;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int TestCaseSolution() {
    sort(a+1, a+1+n);
    int ans = a[1];
    for (int i=2; i<=n; i++)
        ans = max(ans, a[i] - a[i-1]);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << TestCaseSolution() << '\n';
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
