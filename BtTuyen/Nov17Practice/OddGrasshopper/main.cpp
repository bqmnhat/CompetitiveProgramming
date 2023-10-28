#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
long long x, n, d[2] = {1, -1};

long long TestCaseSolution() {
    long long ans = x, tmp = d[abs(x%2)];
    if (n%4 == 1)
        ans = ans + ((-n)*tmp);
    else if (n%4 == 2)
        ans = ans + (1LL*tmp);
    else if (n%4 == 3)
        ans = ans + ((n + 1LL)*tmp);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> x >> n;
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
