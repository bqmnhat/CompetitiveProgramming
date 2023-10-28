#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, b[101], g[101];

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> b[i];
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> g[i];
}

int Solution() {
    int ans = 0;
    sort(b+1, b+1+n);
    sort(g+1, g+1+m);
    for (int i = 1, j = 1; (i<=n) && (j<=m); ) {
        if (abs(b[i] - g[j]) <= 1) {
            ans++;
            i++;
            j++;
        }
        else if (g[j] <= b[i])
            j++;
        else
            i++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    cout << Solution();
    return 0;
}
