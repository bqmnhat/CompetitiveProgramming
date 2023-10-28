#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, m;
ll k, a[MaxN+5], b[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=m; i++)
        cin >> b[i];
}

int Solution() {
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    int i = 1, j = 1, ans = 0;
    while ((i <= n) && (j <= m)) {
        if (abs(b[j] - a[i]) <= k) {
            ans++;
            i++;
            j++;
        }
        else if (b[j] > k + a[i])
            i++;
        else
            j++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    cout << Solution();
    return 0;
}
