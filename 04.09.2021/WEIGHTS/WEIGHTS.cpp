#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int tmp[40], b[40], ltmp = 0, lb = -1;

void DecTo3() {
    while (n > 0) {
        lb++;
        b[lb] = n%3;
        n = n/3;
    }
}

void Solve() {
    for (int i=0; i<=lb+1; i++) {
        if (b[i] == 1)
            cout << i << " ";
        else if (b[i] > 1) {
            if (b[i] == 2) {
                ltmp++;
                tmp[ltmp] = i;
            }
            b[i] = 0;
            b[i+1]++;
        }
    }
    cout << '\n';
    for (int i=1; i<=ltmp; i++) {
        cout << tmp[i] << " ";
    }
}

int main()
{
    freopen("WEIGHTS.INP", "r", stdin);
    freopen("WEIGHTS.OUT", "w", stdout);
    cin >> n;
    DecTo3();
    Solve();
    return 0;
}
