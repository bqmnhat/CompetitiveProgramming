#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
long long k;

void ReadData() {
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
}

long long PairsX(int x) {
    long long i=1, j=n;
    long long ans = 0;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            ans += j-i;
            i++;
        }
        else
            j--;
    }
    return ans;
}

int Solution() {
    int ans = 0;
    int lo=0, hi = 2000000;
    while (lo <= hi) {
        int x = (lo+hi)/2;
        if (PairsX(x) >= k) {
            ans = x;
            hi = x-1;
        }
        else
            lo = x+1;
    }
    return ans;
}

int main()
{
    freopen("KTHSUM.INP", "r", stdin);
    freopen("KTHSUM.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    sort(a+1,a+1+n);
    cout << Solution();
    return 0;
}
