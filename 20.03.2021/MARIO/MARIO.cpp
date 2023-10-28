#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int k = 0;
    for (int i=n; i>=1; i--) {
        k = ((k+a[i])-1)/2+1;
    }
    return k;
}

int main()
{
    freopen("MARIO.INP", "r", stdin);
    freopen("MARIO.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
