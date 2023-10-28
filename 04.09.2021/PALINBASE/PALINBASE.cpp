#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[31], la = 0;

void ChangeBase(int n, int b) {
    while (n > 0) {
        la++;
        a[la] = n%b;
        n = n/b;
    }
}

bool CheckPalin(int la) {
    int i = 1, j = la;
    while (i <= j) {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void Solve() {
    bool Palin = false;
    for (int i=2; i<=16; i++) {
        la = 0;
        ChangeBase(n,i);
        if (CheckPalin(la)) {
            if (!Palin) {
                Palin = true;
                cout << "YES" << " " << i;
            }
            else
                cout << " " << i;
        }
    }
    if (!Palin)
        cout << "NO";
    cout << '\n';
}

int main()
{
    freopen("PALINBASE.INP", "r", stdin);
    freopen("PALINBASE.OUT", "w", stdout);
    cin >> n;
    while (n != 0) {
        Solve();
        cin >> n;
    }
    return 0;
}

