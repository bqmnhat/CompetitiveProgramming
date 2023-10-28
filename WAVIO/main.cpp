#include<bits/stdc++.h>
using namespace std;
#define MaxN 100000
int n, a[MaxN];

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
}

int BinSearch(int lo, int hi, int val, int a[MaxN]) {
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (a[mid] >= val) {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return ans;
}

void revereseArr(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
       swap(arr[i++], arr[j--]);
}

int MaxWavio() {
    if (n == 0)
        return 0;
    int LIS[MaxN], increasing[MaxN], LDS[MaxN], decreasing[MaxN], l = 1;
    LIS[0] = 0;
    increasing[0] = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] < increasing[0]) {
            increasing[0] = a[i];
            LIS[i] = 0;
        }
        else if (a[i] > increasing[l-1]) {
            increasing[l] = a[i];
            LIS[i] = l;
            l++;
        }
        else {
            int tmp = BinSearch(0,l-1,a[i], increasing);
            increasing[tmp] = a[i];
            LIS[i] = tmp;
        }
    }
    revereseArr(a,n);
    l = 1;
    LDS[0] = 0;
    decreasing[0] = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] < decreasing[0]) {
            decreasing[0] = a[i];
            LDS[i] = 0;
        }
        else if (a[i] > decreasing[l-1]) {
            decreasing[l] = a[i];
            LDS[i] = l;
            l++;
        }
        else {
            int tmp = BinSearch(0,l-1,a[i], decreasing);
            decreasing[tmp] = a[i];
            LDS[i] = tmp;
        }
    }
    int ans = 0;
    revereseArr(a,n);
    revereseArr(LDS,n);
    for (int i=0; i<n; i++) {
        ans = max(ans, LIS[i] + LDS[i] + 1);
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << MaxWavio();
    return 0;
}
