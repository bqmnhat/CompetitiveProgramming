#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
int n, t[4*MaxN+1], a[MaxN+1],q;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void build(int v, int tl, int tr) { //Initially v = 1, tl = 1, tr = n
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) { //Initially v = 1, tl = 1, tr = n
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

int getMin(int v, int tl, int tr, int l, int r) { //Initially v = 1, tl = 1, tr = n
    if (l > r)
        return 1e9;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(getMin(v*2, tl, tm, l, min(r, tm)), getMin(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main()
{
    cin >> n;
    ReadData();
    cin >> q;
    build(1, 1, n);
    int l, r;
    for (int i=1; i<=q; i++) {
        cin >> l >> r;
        l++;
        r++;
        cout << getMin(1, 1, n, l, r) << '\n';
    }
    return 0;
}
