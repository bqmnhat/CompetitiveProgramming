#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
struct Time {
    long long val;
    int mode; // mode 1 la start, mode 0 la end
} t[200001];

void ReadData() {
    for (int i=1; i<=2*n; i++) {
        cin >> t[i].val;
        t[i].mode = i%2;
    }
}

bool CmpTime(Time a, Time b) {
    if (a.val == b.val)
        return (a.mode < b.mode);
    return (a.val < b.val);
}

int Solution() {
    sort(t+1,t+1+2*n, CmpTime);
    int Now = 0, MaxMay = 0;
    for (int i=1; i<=2*n; i++) {
        if (t[i].mode == 0) {
            Now--;
        }
        if (t[i].mode == 1) {
            Now++;
        }
        if (Now > MaxMay) {
            MaxMay = Now;
        }
    }
    return MaxMay;
}

int main()
{
    freopen("PHANMAY.INP", "r", stdin);
    freopen("PHANMAY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}

