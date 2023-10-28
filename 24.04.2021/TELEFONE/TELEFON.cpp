#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[300001], cd[300001], n,d;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cd[i] = cd[i-1] + a[i];
    }
}

int Solution() {
    int i=1, ans = 0;
    while (i<n) {
        if (a[i] == 1) {
            if (cd[min(i+d,n)] - cd[i] >= 1) {
                i++;
            }
            else {
                a[i+d] = 1;
                i = i+d;
                ans++;
            }
        }
        else
            i++;
    }
    return ans;
}

int main()
{
    freopen("TELEFON.INP", "r", stdin);
    freopen("TELEFON.OUT", "w", stdout);
    cin >> n >> d;
    ReadData();
    cout << Solution();
    return 0;
}
