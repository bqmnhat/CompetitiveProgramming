#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;
struct Cow {
    long long t, d;
} a[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].t >> a[i].d;
        sum += a[i].d;
    }
}

long long GCD(long long a, long long b) {
    long long tmp;
    while (b > 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

bool CmpCow(Cow a, Cow b) {
    long long m = (a.t*b.t)/GCD(a.t, b.t);
    return ((a.d * (m/a.t)) > (b.d * (m/b.t)));
}

long long MinFlowers() {
    long long ans = 0;
    sort(a+1, a+1+n, CmpCow);
    for (int i=1; i<=n; i++) {
        sum = sum - a[i].d;
        ans += sum*a[i].t*2;
    }
    return ans;
}

int main()
{
    freopen("COWS.INP", "r", stdin);
    freopen("COWS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MinFlowers();
    return 0;
}
