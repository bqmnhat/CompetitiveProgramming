#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int t, n, q;
ll a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void SolveTestCase() {
    int cntEven, cntOdd;
    cntEven = cntOdd = 0;
    ll Sum = 0;
    for (int i=1; i<=n; i++) {
        if (a[i]&1LL)
            cntOdd++;
        else
            cntEven++;
        Sum += a[i];
    }

    for (int i=1; i<=q; i++) {
        int cmd;
        ll x;
        cin >> cmd >> x;
        if (cmd == 0) {
            Sum += cntEven*x;
            if (x&1LL) {
                cntOdd += cntEven;
                cntEven = 0;
            }
        }
        else {
            Sum += cntOdd*x;
            if (x&1LL) {
                cntEven += cntOdd;
                cntOdd = 0;
            }
        }
        cout << Sum << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> q;
        ReadData();
        SolveTestCase();
    }
    return 0;
}
