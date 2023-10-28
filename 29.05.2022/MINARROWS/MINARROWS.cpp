#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
#define MaxH 1000000
using namespace std;
int n, h[MaxN+1], tk[MaxH+2];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (tk[h[i] + 1] > 0) {
            tk[h[i] + 1]--;
            tk[h[i]]++;
        }
        else {
            ans++;
            tk[h[i]]++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINARROWS.INP", "r", stdin);
    freopen("MINARROWS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
