#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, m, a[50001], top = 1;
struct AC {
    long long b, c;
} x[50001];

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> x[i].b >> x[i].c;
    }
}

bool CmpC(AC a, AC b) {
    return (a.c < b.c);
}

long long Solution() {
    sort(x+1, x+1+m, CmpC);
    sort(a+1, a+1+n);
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        while (x[top].b < a[i]) {
            top++;
        }
        ans += x[top].c;
    }
    return ans;
}

int main()
{
    ReadData();
    cout << Solution();
    return 0;
}
