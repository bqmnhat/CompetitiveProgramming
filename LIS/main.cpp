#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000001
using namespace std;
int n, tail[MaxN], a[MaxN];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int BinSearchCeil(const int& val, int lo, int hi, const int arr[MaxN]) {
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (arr[m] >= val) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

int LISLength() {
    int length = 2;
    tail[1] = a[1];
    for (int i = 2; i<=n; i++) {
        if (a[i] < tail[1])
            tail[1] = a[i];
        else if (a[i] > tail[length - 1])
            tail[length++] = a[i];
        else
            tail[BinSearchCeil(a[i], 1, length-1, tail)] = a[i];
    }
    return length-1;
}

int main()
{
    cin >> n;
    ReadData();
    cout << LISLength();
    return 0;
}
