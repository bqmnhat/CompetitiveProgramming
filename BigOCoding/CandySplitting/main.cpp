#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, c[1001], a[1001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i];
    for (int i=1; i<=n; i++)
        a[i] = (a[i-1]^c[i]);
}

int Solution() {
    if (a[n] != 0)
        return -1;
    sort(c+1, c+1+n);
    int ans = 0;
    for (int i=2; i<=n; i++)
        ans += c[i];
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        int tmp = Solution();
        cout << "Case #" << i << ": ";
        if (tmp == -1)
            cout << "NO";
        else
            cout << tmp;
         cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
