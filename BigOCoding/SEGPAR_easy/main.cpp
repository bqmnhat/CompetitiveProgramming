#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k,sum = 0, a[15001];

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

bool check(int mid)
{
    int cnt= 0;
    int Sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > mid)
            return false;
        Sum += a[i];
        if (Sum > mid) {
            cnt++;
            Sum = a[i];
        }
    }
    cnt++;
    if (cnt <= k)
        return true;
    return false;
}

int BinSearch(int sum, int k) {
    int lo = 0, hi = sum, ans = 0;
    while(lo <= hi) {
        int m = (lo + hi)/2;
        if (check(m)) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    ReadData();
    cout << BinSearch(sum, k);
    return 0;
}
