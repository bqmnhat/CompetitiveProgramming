#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double a[5001];
bool b[5001];
int n;

void ReadData() {
    int i = 1;
    while (cin >> a[i])
        i++;
    n = i-1;
}

int BinSearch(int lo, int hi, double val) {
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (a[mid] < val)
            lo = mid+1;
        else if (a[mid] > val)
            hi = mid-1;
        else
            return mid;
    }
    return -1;
}

int Solution() {
    int ans = 0;
    sort (a+1, a+1+n);
    for (int i=1; i<=n-2; i++) {
        for (int j=i+2; j<=n; j++) {
            double val = double(double(a[i]+a[j])/2);
            int ID = BinSearch(i, j, val);
            if ((ID > 0) && (b[ID] == false)) {
                ans++;
                b[ID] = true;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    ReadData();
    cout << Solution();
    return 0;
}
