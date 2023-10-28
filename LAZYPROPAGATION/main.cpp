#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, a[1000001], q;
struct STNode {
    long long val = 0, lazy = 0;
}st[4000001];

void down(int id) {
    long long tmp = st[id].lazy;
    st[id*2].val += tmp;
    st[id*2].lazy += tmp;
    st[id*2+1].val += tmp;
    st[id*2+1].lazy += tmp;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, long long val) {
    if ((l > v) || (r < u))
        return;
    if ((u <= l) && (r <= v)) {
        st[id].val += val;
        st[id].lazy += val;
        return;
    }
    down(id);
    int mid = (l + r)/2;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

int getMax(int id, int l, int r, int u, int v) {
    if ((l > v) || (r < u))
        return -1e9;
    if ((u <= l) && (r <= v))
        return st[id].val;
    down(id);
    int mid = (l + r)/2;
    return max(getMax(id*2, l, mid, u, v), getMax(id*2+1, mid+1, r, u, v));
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int x, y, k;
            cin >> x >> y >> k;
            update(1,1,n,x,y,k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << getMax(1,1,n,x,y) << '\n';
        }
    }
}

int main()
{
    cin >> n >> q;
    Solve();
    return 0;
}
