#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, t[1200001];

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r)
        return;
    if (tl == tr) {
        if ((new_val != tl) && (t[v] == 0))
            t[v] = new_val;
        return;
    }
    if (l >= tl && r <= tr) {
        int tm = (tl + tr)/2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        t[v] = new_val;
    }
}

int getWinner(int v, int tl, int tr, int pos) { //Initially v = 1, tl = 1, tr = n
    if (tr == tl)
        return t[v];
    if ((pos <= tr) && (pos >= tl)) {
        int tm = (tl + tr) / 2, tmp = 0;
        if (pos <= tm)
            tmp = getWinner(v*2, tl, tm, pos);
        else
            tmp = getWinner(v*2+1, tm+1, tr, pos);
        if (tmp != 0)
            return tmp;
        return t[v];
    }
}

void Solve() {
    for (int i=1; i<=m; i++) {
        int l,r,x;
        cin >> l >> r >> x;
        update(1,1,n,l,r,x);
    }
    for (int i=1; i<=n; i++) {
        int tmp = getWinner(1,1,n,i);
        if (tmp == i)
            cout << "0 ";
        else
            cout << tmp << ' ';
    }
}

int main()
{
    cin >> n >> m;
    Solve();
    return 0;
}
