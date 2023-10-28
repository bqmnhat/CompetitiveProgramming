#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Cow {
    long long t,d;
} a[100001];
int n;
long long sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].t >> a[i].d;
        sum += a[i].d;
    }
}

long long UCLN(long long x, long long y) {
    long long tmp;
    while (y > 0) {
        tmp = y;
        y = x%y;
        x = tmp;
    }
    return x;
}

bool CowCmp(Cow a, Cow b) {
    long long m = (a.t*b.t)/UCLN(a.t, b.t);
    return (a.d*(m/a.t) > b.d*(m/b.t));
}

long long Flowers() {
    long long ans = 0;
    sort(a+1, a+1+n, CowCmp);
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
    cout << Flowers();
    return 0;
}
