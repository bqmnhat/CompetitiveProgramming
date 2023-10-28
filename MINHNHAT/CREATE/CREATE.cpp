#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[10001];

int LengthOf(int n) {
    int ans = 0;
    while (n>0) {
        n = n/10;
        ans = ans + 1;
    }
    return ans;
}

bool Comp(int a, int b) {
    int la = LengthOf(a);
    int lb = LengthOf(b);
    while (LengthOf(a) < LengthOf(b))
        a = a * 10;
    while (LengthOf(b) < LengthOf(a))
        b = b * 10;
    if (a == b)
        return (la > lb);
    return (a < b);
}

void Solve() {
    sort(a+1, a+1+n, Comp);
    for (int i=1; i<=n; i++) {
        cout << a[i];
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    freopen("CREATE.INP", "r", stdin);
    freopen("CREATE.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
