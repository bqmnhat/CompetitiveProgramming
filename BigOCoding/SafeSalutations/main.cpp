#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c[10] = {1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};

void Solve() {
    while (cin >> n)
        cout << c[n-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
