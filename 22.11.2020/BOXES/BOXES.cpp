#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[101],n,m;

void ReadData() {
    int c,b;
    for (int i = 1; i<=n; i++) {
        cin >> c >> b;
        if (c > a[b])
            a[b] = c;
    }
}

int MaxVal() {
    int ans = 0;
    for (int i = 1; i<=m; i++) {
        ans = ans + a[i];
    }
    return ans;
}

int main()
{
    freopen("BOXES.INP", "r", stdin);
    freopen("BOXES.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << MaxVal();
    return 0;
}
