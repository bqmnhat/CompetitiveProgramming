#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 1000000
int n, c[MaxN+1],L[MaxN+1], R[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
}

void MakeLeftRight() {
    int tmp = 1;
    L[1] = 0;
    for (int i=2; i<=n; i++) {
        L[i] = tmp;
        if (c[i] == c[i-1])
            tmp++;
        else
            tmp = 1;
    }
    tmp = 1;
    R[n] = 0;
    for (int i=n-1; i>=1; i--) {
        R[i] = tmp;
        if (c[i] == c[i+1])
            tmp++;
        else
            tmp = 1;
    }
}

long long MaxLamps() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if ((c[i-1] == c[i+1]) && (L[i] + R[i] + 1 > ans))
            ans = L[i] + R[i] + 1;
        if ((c[i-1] != c[i+1]) && ((L[i]+1 > ans)||(R[i]+1 > ans)))
            ans = max(L[i]+1, R[i]+1);
    }
    return ans;
}

int main()
{
    freopen("LAMPS.INP", "r", stdin);
    freopen("LAMPS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeLeftRight();
    cout << MaxLamps();
    return 0;
}
