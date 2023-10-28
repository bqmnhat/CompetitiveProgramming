#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, pow2[21];
long long a[36], b[3][19], T, seg1[2000001], seg2[2000001], sum1 = 0, sum2 = 0, sl1 = 0, sl2 = 0;

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
}

void MakePow() {
    pow2[0] = 1;
    for (int i=1; i<=18; i++) {
        pow2[i] = pow2[i-1]*2;
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

void MakeSeg() {
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

int BinSearch(long long val) {
    int lo = 1, hi = sl2, ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (seg2[m] >= val) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

long long Solution() {
    long long ans = 0;
    sort(seg1+1, seg1+1+sl1);
    sort(seg2+1, seg2+1+sl2);
    for (int i=1; i<=sl1; i++) {
        long long tmp = BinSearch(T - seg1[i]);
        if (tmp != -1)
            ans = ans + (sl2 - tmp + 1);
    }
    return ans;
}

int main()
{
    freopen("EXAMS.INP", "r", stdin);
    freopen("EXAMS.OUT", "w", stdout);
    cin >> n >> T;
    ReadData();
    MakePow();
    MakeSeg();
    cout << Solution();
    return 0;
}
