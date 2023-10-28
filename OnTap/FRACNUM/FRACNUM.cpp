#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

long long FindSum(long long m) {
    long long ans;
    ans = ((m+1)*m)/2;
    return ans;
}

long long BinsearchHigh(long long val) {
    long long lo = 1, hi = 2e9;
    long long ans = -1;
    while (lo <= hi) {
        long long m = (lo + hi)/2;
        long long tmp = FindSum(m);
        if (tmp >= val) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m+1;
    }
    return ans;
}

long long BinsearchLow(long long val) {
    long long lo = 1, hi = 2e9;
    long long ans = -1;
    while (lo <= hi) {
        long long m = (lo + hi)/2;
        long long tmp = FindSum(m);
        if (tmp <= val) {
            ans = m;
            lo = m + 1;
        }
        else
            hi = m-1;
    }
    return ans;
}

void Solve() {
    long long HeadLow = BinsearchLow(n), HeadHigh = BinsearchHigh(n), p, q;
    long long xLow = FindSum(HeadLow), xHigh = FindSum(HeadHigh);
    if ((xLow == n) && (HeadLow%2 == 0)) {
        cout << "1" <<"/"<<HeadLow;
        return;
    }
    if ((xHigh == n) && (HeadHigh%2 != 0)) {
        cout << HeadHigh << "/" << "1";
        return;
    }
    if (HeadLow % 2 != HeadHigh % 2) {
        xLow++;
    }
    if (HeadLow % 2 == 0) {
        p = 1 + (n - xLow);
        q = 1 + (xHigh - n);
    }
    else {
        p = 1 + (xHigh - n);
        q = 1 + (n - xLow);
    }
    cout << p << '/' << q;
}

int main()
{
    freopen("FRACNUM.INP", "r", stdin);
    freopen("FRACNUM.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
