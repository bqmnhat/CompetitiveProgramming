#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2005
#define MaxP 4000005
using namespace std;
typedef long long ll;
struct Pair{
    ll Sum;
    int i, j;
} p[MaxP+1];
int n, d, lp = 0;
ll a[MaxN+1];
bool mark[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakePairs() {
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j)
                continue;
            lp++;
            p[lp] = {a[i] + a[j], i, j};
        }
    }
}

bool CmpPairs(Pair a, Pair b) {
    if (a.Sum == b.Sum) {
        if (a.i == b.i)
            return (a.j > b.j);
        return (a.i < b.i);
    }
    return (a.Sum < b.Sum);
}

ll Solution() {
    ll cnt = 0, tmpcnt = 0;
    sort(p + 1, p + lp + 1, CmpPairs);
    int i = 1, j = 0;
    p[lp+1] = {-1, -1, -1};
    while (j < lp) {
        tmpcnt = 0;
        memset(mark, false, sizeof(mark));
        j++;
        while ((p[j].Sum == p[j+1].Sum) && (j < lp))
            j++;
        while ((p[i].Sum < p[j].Sum - d) && (i < j))
            i++;
        int t = i-1;
        while (t < j) {
            t++;
            if ((!mark[p[t].i]) && (!mark[p[t].j])) {
                mark[p[t].i] = mark[p[t].j] = true;
                tmpcnt++;
            }
        }
        cnt = max(cnt, tmpcnt);
    }
    cnt = max(cnt, tmpcnt);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);
    cin >> n >> d;
    ReadData();
    MakePairs();
    cout << Solution();
    return 0;
}
