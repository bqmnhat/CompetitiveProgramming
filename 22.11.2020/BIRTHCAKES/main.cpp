#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000001], n;
bool b[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int MinPiles() {
    int ans = n, i = 1, j = n/2+1, m = n/2;
    sort(a+1, a+1+n);
    while ((i<=m) && (j<=n)) {
        if (a[i] <= a[j]/2) {
            ans--;
            i++;
            j++;
        }
        else
            j++;
    }
    return ans;
}

int main()
{
    freopen("BIRTHCAKES.INP", "r", stdin);
    freopen("BIRTHCAKES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MinPiles();
    return 0;
}

