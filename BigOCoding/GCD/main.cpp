#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void Solve() {
    cin >> n;
    while (n != 0) {
        ll G = 0;
        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
                G += __gcd(i,j);
        cout << G << '\n';
        cin >> n;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
