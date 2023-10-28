#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e6;
int n, t[4*MaxN], a[MaxN];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void build(int a[], int v, int tl, int tr) { //Initially v = 1, tl = 1, tr = n
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
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
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) { //Initially v = 1, tl = 1, tr = n
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main()
{
    cin >> n;
    ReadData();
    build(a, 1, 1, n);
    int l, r;
    cin >> l >> r;
    cout << sum(1, 1, n, l, r);
    return 0;
}
