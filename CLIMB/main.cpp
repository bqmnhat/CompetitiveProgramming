#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, h[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
}

int Solution() {
    int ans = 0, st = 1;
    for (int i=2; i<=n; i++) {
        if (h[i] >= h[i-1]) {
            if (h[i] - h[st] > ans)
                ans = h[i] - h[st];
        }
        else
            st = h[i];
    }
    return ans;
}

int main()
{
    freopen("CLIMB.INP", "r", stdin);
    freopen("CLIMB.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
