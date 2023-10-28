#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
struct Cake {
    long long r;
    long long c;
} a[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].r >> a[i].c;
    }
}

bool CmpCake(Cake a, Cake b) {
    if (a.r*a.r*b.c == b.r*b.r*a.c) {
        return (a.c < b.c);
    }
    return (a.r*a.r*b.c > b.r*b.r*a.c);
}

long long CakeCost() {
    sort(a+1, a+1+n, CmpCake);
    long long ans = 0;
    for (int i=1; i<=k; i++) {
        ans = ans + a[i].c;
    }
    return ans;
}

int main()
{
    freopen("PIZZA.INP", "r", stdin);
    freopen("PIZZA.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << CakeCost();
    return 0;
}
