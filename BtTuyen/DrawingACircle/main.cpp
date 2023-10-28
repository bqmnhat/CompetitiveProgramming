#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int d,t,n,a,b;

void Solve() {
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        int tmp = min(a,b);
        if (d <= tmp)
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
    cin >> d >> t >> n;
    Solve();
    return 0;
}
