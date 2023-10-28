#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k, a[201];
bool Succeed = true;

void PrintAns() {
    for (int i=200; i>=1; i--) {
        if (a[i] != 0) {
            cout << i << " " << a[i] << endl;
        }
    }
}

void Solve() {
    for (int i=k; i>1; i--) {
        if (k%i == 0) {
            if (n%i == 1) {
                continue;
            }
            int c = n/i;
            a[i] += c;
            n = n%i;
        }
    }
    if (n > 0) {
        Succeed = false;
    }
    if (Succeed == true) {
        PrintAns();
    }
    else
        cout << "0";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PHANTICH.INP", "r", stdin);
    freopen("PHANTICH.OUT", "w", stdout);
    cin >> n >> k;
    Solve();
    return 0;
}
