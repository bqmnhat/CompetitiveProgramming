#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n;

void Solve() {
    ll sum = 0;
    for (int i=1; i<n; i++) {
        ll ai;
        cin >> ai;
        sum += ai;
        cout << sum%(1LL*(n-i)) << ' ';
        sum = sum - (sum%(1LL*(n-i)));
    }
    ll ai;
    cin >> ai;
    sum += ai;
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
