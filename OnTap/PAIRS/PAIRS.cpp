#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long h[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
}

int BinSearch(int en, long long val) {
    int lo = 1, hi = en;
    int ans = en+1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (h[m] >= val) {
            ans = m;
            hi = m-1;
        }
        else
            lo = m+1;
    }
    return ans;
}

long long PairUp() {
    long long ans = 0;
    sort(h+1, h+1+n);
    for (int i=n; i>=2; i--) {
        long long tmp = (((h[i]*90)-1)/100) + 1;
        ans = ans + (i - BinSearch(i-1,tmp));
    }
    return ans;
}

int main()
{
    freopen("PAIRS.INP", "r", stdin);
    freopen("PAIRS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << PairUp();
    return 0;
}
