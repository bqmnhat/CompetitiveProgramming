#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a[101];
int t,n;

void ReadData() {
    for (int i=1; i<=n-2; i++)
        cin >> a[i];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        string ans = "";
        ans = ans + a[1][0];
        for (int i=2; i<=n-2; i++) {
            if (a[i][0] == a[i-1][1])
                ans = ans + a[i][0];
            else {
                ans = ans + a[i-1][1];
                ans = ans + a[i][0];
            }
        }
        ans = ans + a[n-2][1];
        int l = ans.length();
        while (l < n) {
            ans = ans + "a";
            l++;
        }
        cout << ans << '\n';
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
