#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, R, x[1000001], Selected[1000001];
struct Seg {
    int x,y,id;
} seg[1000002];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> x[i];
}

void MakeSeg() {
    for (int i=1; i<=m; i++)
        seg[i] = {x[i] - R, x[i] + R, i};
}

void PrintAns(int ans) {
    cout << ans << '\n';
    for (int i=1; i<=ans; i++)
        cout << Selected[i] << ' ';
}

bool CmpSeg(Seg a, Seg b) {
    return (a.x < b.x);
}

void Solve() {
    seg[++m] = {1000001, 1000001, m};
    sort(seg+1, seg+1+m, CmpSeg);
    int r = -1, ans = 0;
    for (int i=1; i<=m; i++) {
        if (seg[i].x > r + 1) {
            r = seg[i-1].y;
            ans++;
            Selected[ans] = seg[i-1].id;
        }
        if (r >= n-1)
            break;
    }
    if (r < n-1)
        cout << '0';
    else
        PrintAns(ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("STATION.INP", "r", stdin);
    freopen("STATION.OUT", "w", stdout);
    cin >> n >> m >> R;
    ReadData();
    MakeSeg();
    Solve();
    return 0;
}
