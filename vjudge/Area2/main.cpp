#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pdd;
int n, a;
pdd x[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i].first >> x[i].second;
}

ld Dist(pdd a, pdd b) {
    ld ans = sqrt( ((b.first - a.first)*(b.first - a.first)) + ((b.second - a.second)*(b.second - a.second)));
    return ans;
}

bool In4Circle(pdd p) {
    ld dist1 = Dist(pdd(0, a), p);
    ld dist2 = Dist(pdd(0, 0), p);
    ld dist3 = Dist(pdd(a, 0), p);
    ld dist4 = Dist(pdd(a, a), p);
    if ((dist1 <= ld(a)) && (dist2 <= ld(a)) && (dist3 <= ld(a)) && (dist4 <= ld(a)))
        return true;
    return false;
}

ld Solution() {
    int m = 0;
    for (int i=1; i<=n; i++)
        if (In4Circle(x[i]))
            m++;
    ld ans = ld(m*a*a)/ld(n);
    return ans;
}

void Solve() {
    while ((cin >> n >> a) && ((n != 0) || (a != 0))) {
        ReadData();
        cout << setprecision(5) << fixed << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
