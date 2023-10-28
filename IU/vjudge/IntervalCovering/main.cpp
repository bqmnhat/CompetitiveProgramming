#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef pair<double, double> pdd;
typedef long long ll;
int n;
ll l, w;
pdd Segs[MaxN+1];

void ReadData() {
    double HalfW = double(w)/2.0;
    int NewN = 0;
    for (int i=1; i<=n; i++) {
        ll pos, r;
        cin >> pos >> r;
        if (r > HalfW) {
            NewN++;
            double tmp = sqrt(double(r*r) - (HalfW*HalfW));
            Segs[NewN].first = double(pos) - tmp;
            Segs[NewN].second = double(pos) + tmp;
        }
    }
    n = NewN;
}

bool CmpSegs(pdd a, pdd b) {
    if (a.first == b.first)
        return (a.second > b.second);
    return (a.first < b.first);
}

int Solution() {
    int ans = 0, i = 1;
    double RightEnd = 0;
    sort(Segs+1, Segs+1+n);
    while ((i<=n) && (RightEnd < l)) {
        if (Segs[i].first > RightEnd)
            break;
        int j;
        for (j=i+1; (j<=n) && (Segs[j].first <= RightEnd); j++)
            if (Segs[j].second > Segs[i].second)
                i = j;
        ans++;
        RightEnd = Segs[i].second;
        i = j;
    }
    if (RightEnd >= l)
        return ans;
    else
        return -1;
}

void Solve() {
    while (cin >> n >> l >> w) {
        ReadData();
        cout << Solution() << '\n';
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
