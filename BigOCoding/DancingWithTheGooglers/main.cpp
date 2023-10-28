#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tc,n,s,p,t[101];

void ReadData() {
    for (int i=1;i <= n; i++)
        cin >> t[i];
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (t[i] >= max(0,(3*p - 2)))
            ans++;
        else if ((t[i] >= max(2,(3*p - 4))) && (s > 0)) {
            ans++;
            s--;
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=tc; i++) {
        cin >> n >> s >> p;
        ReadData();
        cout << "Case #" << i << ": " << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    Solve();
    return 0;
}
