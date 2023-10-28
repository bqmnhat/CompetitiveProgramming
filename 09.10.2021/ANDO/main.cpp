#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,a[300001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int CountPattern(int pattern) {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if ((pattern & a[i]) == pattern)
            ans++;
    }
    return ans;
}

int Solution() {
    int ans = 0;
    for (int i=31; i>=0; i--) {
        int tmp = (ans | (1 << i));
        int cnt = CountPattern(tmp);
        if (cnt >= 2)
            ans = tmp;
    }
    return ans;
}

int main()
{
    freopen("ANDO.INP", "r", stdin);
    freopen("ANDO.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
