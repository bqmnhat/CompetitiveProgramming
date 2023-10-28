#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001], cid;
struct Node {
    int val;
    int id;
};
Node st[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Build(int id, int l, int r) {
    if (l == r) {
        st[id].val = a[l];
        st[id].id = l;
        return;
    }
    int mid = (l+r)/2;
    Build(id*2, l, mid);
    Build(id*2+1, mid+1, r);
    if (st[id*2].val >= st[id*2+1].val) {
        st[id] = st[id*2];
    }
    else
        st[id] = st[id*2+1];
}

void update(int id, int l, int r, int i, int v) {
    if ((i < l) || (r < i)) {
        return ;
    }
    if (l == r) {
        st[id].val = v;
        return ;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);
    if (st[id*2].val >= st[id*2+1].val) {
        st[id] = st[id*2];
    }
    else {
        st[id] = st[id*2+1];
    }
}

Node get(int id, int l, int r, int u, int v) {
    if ((v < l) || (r < u)) {
        Node tmp;
        tmp.id = -1;
        tmp.val = -1;
        return tmp;
    }
    if ((u <= l) && (r <= v)) {
        return st[id];
    }
    int mid = (l + r) / 2;
    Node nleft = get(id*2, l, mid, u, v), nright = get(id*2 + 1, mid+1, r, u, v);
    if (nleft.val >= nright.val) {
        return nleft;
    }
    else {
        return nright;
    }
}

void Solve() {
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        update(1, 1, n, i, a[i]);
    }
    for (int i=1; i<=m; i++) {
        Node tmp = get(1, 1, n, 1, n);
        ans += tmp.val;
        update(1, 1, n, tmp.id, ((tmp.val-1)/2+1));
    }
    cout << ans;
}

int main()
{
    cin >> n >> m;
    ReadData();
    Build(1,1,n);
    Solve();
    return 0;
}
