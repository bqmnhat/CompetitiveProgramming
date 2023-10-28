#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void Solve() {
    long long sum = 0, ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        sum = sum + ai;
    }
    if (sum %2 == 0)
        cout << "YES";
    else
        cout << "NO";
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
