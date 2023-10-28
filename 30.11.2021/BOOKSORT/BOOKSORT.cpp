#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[300001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int ans = 0, tt = n;
    for (int i=n; i>=1; i--) {
        if (a[i] != tt)
            ans++;
        else
            tt--;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BOOKSORT.INP", "r", stdin);
    freopen("BOOKSORT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
