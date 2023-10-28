#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, ltk = 0;
long long a[500001];
struct ThongKe {
    long long cnt,  actval;
} tk[500001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void MakeTK() {
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        if (a[i] != a[i-1])
            ltk++;
        tk[ltk].cnt++;
        tk[ltk].actval = a[i];
    }
}

int BinSearchLower(int lo, int hi, long long val)  {
    int ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (a[m] < val) {
            ans = m;
            lo = m+1;
        }
        else
            hi = m-1;
    }
    return ans;
}

long long Solution() {
    long long ans = 0;
    for (int i=1; i<=ltk; i++) {
        if (tk[i].cnt >= 2) {
            ans = ans + (tk[i].cnt * (tk[i].cnt-1) * (tk[i].cnt-2))/6;
            long long tmp = BinSearchLower(1,n, tk[i].actval*2);
            long long c = tmp - tk[i].cnt;
            ans = ans + (((tk[i].cnt*(tk[i].cnt-1))/2)*c);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    MakeTK();
    cout << Solution();
    return 0;
}
