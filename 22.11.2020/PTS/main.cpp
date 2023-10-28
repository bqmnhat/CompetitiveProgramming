#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100001], b[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
}

long long MaxPairs() {
    long long i=1, j=1, ans = 0;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    while ((i <= n) && (j <= m)) {
        if (b[j] > a[i]) {
            ans += m-j+1;
            i++;
        }
        else
            j++;
    }
    return ans;
}

int main()
{
    freopen("PTS.INP", "r", stdin);
    freopen("PTS.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << MaxPairs();
    return 0;
}
