#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, s[200000], a[100000];

bool NextSpace(int &p) {
    while ((s[p] != 0) && (p <= 2*n)) {
        p += 1;
    }
    if (p > 2*n) {
        return false;
    }
    return true;
}

void Solve() {
    int p = 1, i = 1;
    while (NextSpace(p) == true) {
        s[p] = 1;
        s[p + a[i] + 1] = 2;
        i = i + 1;
    }
    for (int i=1; i<=2*n; i++) {
        if (s[i] == 1)
            cout << '(';
        if (s[i] == 2)
            cout << ')';
    }
}

void ReadData(int a[], int n) {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    freopen("BRACKETS.INP", "r", stdin);
    freopen("BRACKETS.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    Solve();
    return 0;
}
