#include<iostream>
#include<bits/stdc++.h>
#define MaxN 100005
using namespace std;
struct Vertex {
    Vertex *l, *r;
    int sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val){}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
int n, q, a[MaxN+1];
vector<Vertex*> root;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

Vertex* BuildSt(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = ((tl + tr) >> 1);
    return new Vertex(BuildSt(tl, tm), BuildSt(tm+1, tr));
}

Vertex* UpdateSt(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = ((tl + tr) >> 1);
    if (pos <= tm)
        return new Vertex(UpdateSt(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, UpdateSt(v->r, tm+1, tr, pos));
}

int FindKth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = ((tl + tr) >> 1);
    int left_count = (vr->l->sum) - (vl->l->sum);
    if (left_count >= k)
        return FindKth(vl->l, vr->l, tl, tm, k);
    return FindKth(vl->r, vr->r, tm+1, tr, k-left_count);
}

void Solve() {
    root.push_back(BuildSt(0, MaxN+1));
    for (int i=0; i<n; i++)
        root.push_back(UpdateSt(root.back(), 0, MaxN+1, a[i]));
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        int kth = ((b - a + 2) >> 1);
        int ans = FindKth(root[a-1], root[b], 0, MaxN+1, kth);
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
