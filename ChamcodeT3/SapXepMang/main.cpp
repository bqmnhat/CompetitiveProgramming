#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[10000001];

void ReadData() {
    for (int i=1; i<=n ;i++) {
        cin >> a[i];
    }
}

void PrintAns() {
    for (int i=1; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << a[n];
}

void Solve() {
    sort(a+1, a+1+n);
    PrintAns();
    cout << '\n';
    sort(a+1, a+1+n, greater<ll>());
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
