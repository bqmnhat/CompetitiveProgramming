#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TimeFlag {
    int val, x; // x = 2 la bat dau, x = 0 la ket thuc
} a[100001];
int n;

void ReadData() {
    for (int i=1; i<=2*n; i++) {
        cin >> a[i].val;
        a[i].x = i%2;
    }
}

bool Compare(TimeFlag a, TimeFlag b) {
    if (a.val != b.val) {
        return (a.val < b.val);
    }
    else {
        return (a.x < b.x);
    }
}

int Collapse() {
    int ans = 0, d = 0;
    sort(a+1,a+1+2*n, Compare);
    for (int i=1; i<=2*n; i++) {
        if (a[i].x == 1) {
            ans += d;
            d++;
        }
        if (a[i].x == 0) {
            d--;
        }
    }
    return ans;
}

int main()
{
    freopen("TVSHOW.INP", "r", stdin);
    freopen("TVSHOW.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Collapse();
    return 0;
}
