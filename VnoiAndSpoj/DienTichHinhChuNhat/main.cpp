#include <iostream>
#include <bits/stdc++.h>
#define MaxY 30001
#define MaxN 10000
using namespace std;
typedef long long ll;
typedef pair<int, int> pll;
struct Edge {
    int x, y1, y2, t;
} a[2*MaxN+1];
int n;
pll st[4*MaxY+1]; // node.first == count of rectangles shaded ALL the length
//node.second == the length that is shaded by rectangles in between the corresponding segment

void ReadData() {
    int x1, y1, x2, y2;
    for (int i=1; i<=n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1, y2, 1};
        a[n+i] = {x2, y1, y2, -1};
    }
}

void UpdateSt(int v, int tl, int tr, int l, int r, int type) {
    if ((tl > r) || (tr < l))
        return;
    if ((l <= tl) && (tr <= r)) {
        st[v].first += type;
        if (type == 1)
            st[v].second = (tr - tl + 1);
        else {
            if (st[v].first == 0) {// meaning that there is no rectangle shade all the segment BUT there might be some rectangles shade some partial segment in the current segment
                if (tl == tr)
                    st[v].second = 0;
                else
                    st[v].second = st[2*v].second + st[2*v+1].second;
            }
        }
        return;
    }
    int tm = (tl + tr)/2;
    UpdateSt(v*2, tl, tm, l, r, type);
    UpdateSt(v*2+1, tm+1, tr, l, r, type);
    if (st[v].first == 0) {
        if (tl == tr)
            st[v].second = 0;
        else
            st[v].second = st[2*v].second + st[2*v+1].second;
    }
}

bool CmpEdge(Edge a, Edge b) {
    if (a.x == b.x)
        return (a.t > b.t);
    return (a.x < b.x);
}

ll Solution() {
    ll ans = 0;
    sort(a+1, a+1+2*n, CmpEdge);
    int PreX = 0;
    for (int i=1; i<=2*n; i++) {
        ans += (a[i].x - PreX)*(st[1].second);
        UpdateSt(1, 0, MaxY, a[i].y1, a[i].y2-1, a[i].t);
        PreX = a[i].x;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
