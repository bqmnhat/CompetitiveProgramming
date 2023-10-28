#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a[2][5] = {
    {0,0,1,1},
    {1,1,0,0}
};
long long n, k[61];

void MakeK() {
    k[0] = 1;
    for (int i=1; i<=60; i++) {
        k[i] = k[i-1]*2;
    }
}

long long UpperB(long long x) {
    long long ans, l = 1, r = 60;
    while (l <= r) {
        long long m = (l + r)/2;
        if (k[m] >= x) {
            ans = k[m];
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
}

int NthBit() {
    long long bit4 = ((n-1)/4) + 1;
    int st = 0;
    long long l = 1, r = UpperB(bit4);
    while (l < r) {
        long long m = (l+r)/2;
        if (bit4 <= m)
            r = m;
        else {
            l = m + 1;
            st = 1 - st;
        }
    }
    return a[st][n%4];
}

int main()
{
    freopen("INVERSEQ.INP", "r", stdin);
    freopen("INVERSEQ.OUT", "w", stdout);
    MakeK();
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << NthBit() << '\n';
    }
    return 0;
}

