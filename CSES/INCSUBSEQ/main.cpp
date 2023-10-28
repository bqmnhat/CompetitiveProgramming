#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 200000
int n;
long long a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int BinSearch(int lo, int hi, int val, int a[MaxN+1]) {
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (a[mid] >= val) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int LIS() {
    int LIS[MaxN+1], l = 1;
    LIS[1] = a[1];
    for (int i=2; i<=n; i++) {
        if (a[i] < LIS[1])
            LIS[1] = a[i];
        else if (a[i] > LIS[l]) {
            l++;
            LIS[l] = a[i];
        }
        else
            LIS[BinSearch(1,l,a[i],LIS)] = a[i];
    }
    return l;
}

int main()
{
    cin >> n;
    ReadData();
    cout << LIS();
    return 0;
}
