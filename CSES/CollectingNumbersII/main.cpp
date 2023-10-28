#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, m, IdVal[MaxN+5];
pii a[MaxN+5];
struct Node {
    int ans, last, first;
} st[4*MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        IdVal[i] = a[i].first;
    }
}

Node CombineNode(Node Left, Node Right) {
    Node ans;
    ans.first = Left.first;
    ans.last = Right.last;
    ans.ans = Left.ans + Right.ans;
    if (Left.last < Right.first)
        ans.ans--;
    return ans;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        st[v].ans = 1;
        st[v].first = a[tl].second;
        st[v].last = a[tl].second;
    }
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = CombineNode(st[v*2], st[v*2+1]);
    }
}

void UpdateSt(int v, int tl, int tr, int id, int val) {
    if (tl == tr) {
        st[v].ans = 1;
        st[v].first = val;
        st[v].last = val;
    }
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = CombineNode(st[v*2], st[v*2+1]);
    }
}

void Solve() {
    sort(a+1, a+1+n);
    BuildSt(1, 1, n);
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        swap(IdVal[x], IdVal[y]);
        UpdateSt(1, 1, n, IdVal[x], x);
        UpdateSt(1, 1, n, IdVal[y], y);
        cout << st[1].ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
