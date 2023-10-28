#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, b[3][40], pow2[21];
ll S, a[40], Tmp = 0, sum1 = 0, sum2 = 0, sl1 = 0, sl2 = 0, seg1[2000000], seg2[2000000];

void MakePow() {
    pow2[0] = 1;
    for (int i=1; i<=20; i++) {
        pow2[i] = pow2[i-1]*2;
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Next(int x, int m) {
    int i = 0;
    while ((b[x][i] != 0) && (i < m)) {
        b[x][i] = 0;
        if (x == 1)
            sum1 = sum1 - a[i];
        else
            sum2 = sum2 - a[i+(n/2)];
        i++;
    }
    b[x][i] = 1;
    if (x == 1)
        sum1 = sum1 + a[i];
    else
        sum2 = sum2 + a[i+(n/2)];
}

void GenSum() {
    int m = n/2;
    for (int i=0; i<pow2[m]; i++) {
        sl1++;
        seg1[sl1] = sum1;
        Next(1,m);
    }
    m = n-m;
    for (int i=0; i<pow2[m]; i++) {
        sl2++;
        seg2[sl2] = sum2;
        Next(2,m);
    }
}

int BinSearch(int lo, int hi, ll val) {
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (seg2[m] == val)
            return m;
        else if (seg2[m] < val)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

int MaxVisit() {
    int ans = 0;
    for (int i=1; i<=sl1; i++) {
        int tmp = BinSearch(1, sl2, S - seg1[i]);
        if (tmp != -1) {
            ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("TRAVEL.INP", "r", stdin);
    freopen("TRAVEL.OUT", "w", stdout);
    cin >> n;
    MakePow();
    ReadData();
    GenSum();
    cout << MaxVisit();
    return 0;
}
