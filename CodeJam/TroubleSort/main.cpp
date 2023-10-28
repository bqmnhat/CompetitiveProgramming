#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, nOdd, nEven, aOdd[MaxN+5], aEven[MaxN+5];

void ReadData() {
    nOdd = nEven = 0;
    for (int i=1; i<=n; i++) {
        if (i&1)
            cin >> aOdd[++nOdd];
        else
            cin >> aEven[++nEven];
    }
}

int FirstErr() {
    sort(aOdd+1, aOdd+1+nOdd);
    sort(aEven+1, aEven+1+nEven);
    int i=1, j=1, id = 1, pre = 0;
    while (id <= n) {
        if (id&1) {
            if (aOdd[i] < pre)
                return id-2;
            pre = aOdd[i];
            i++;
        }
        else {
            if (aEven[j] < pre)
                return id-2;
            pre = aEven[j];
            j++;
        }
        id++;
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << "Case #" << i << ": ";
        int FirstE = FirstErr();
        if (FirstE == -1)
            cout << "OK";
        else
            cout << FirstE;
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
