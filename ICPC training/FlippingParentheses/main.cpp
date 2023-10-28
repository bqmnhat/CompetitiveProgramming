#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300010
using namespace std;
string s;
int sum[MaxN];
int n, q, l;
struct Node {
    int l, r, add;
} st[MaxN * 4];

int ParenVal(int i) {
    if (s[i] == '(')
        return 1;
    else
        return -1;
}

void down(int StId) { // lazy prop push down
    // lazy prop under1
    st[StId*2].l += st[StId].add;
    st[StId*2].r += st[StId].add;
    st[StId*2].add += st[StId].add;
    // lazy prop under2
    st[StId*2 + 1].l += st[StId].add;
    st[StId*2 + 1].r += st[StId].add;
    st[StId*2 + 1].add += st[StId].add;
    st[StId].add = 0;
}

void build(int StId, int L, int R) {
    st[StId].add = 0;
    if (L == R) {
        st[StId].l = sum[L] - L;
        st[StId].r = sum[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(StId*2, L, mid);
    build(StId*2 + 1, mid + 1, R );
    st[StId].l = min(st[StId*2 + 1].l, st[StId*2].l);
    st[StId].r = min(st[StId*2 + 1].r, st[StId*2].r);
}

void update(int StId, int L, int R, int x, int add) {
    if (x <= L) {
        st[StId].l += add;
        st[StId].r += add;
        st[StId].add += add;
        return ;
    }
    down(StId);
    int mid = (L+R)/2;
    if (x <= mid)
        update(StId*2, L, mid, x, add);
    update(StId*2 + 1, mid + 1, R, x, add);
    st[StId].l = min(st[StId*2 + 1].l, st[StId*2].l);
    st[StId].r = min(st[StId*2 + 1].r, st[StId*2].r);
}

int CloseSolution(int StId, int L, int R) {
    if (L == R)
        return L;
    int mid = (L+R)/2;
    down(StId);
    if (st[StId*2].l < 0)
        return CloseSolution(StId*2, L, mid);
    else
        return CloseSolution((StId*2) + 1, mid+1, R) ;
}

int OpenSolution(int StId, int L, int R) {
    if (L == R)
        return (L+1);
    int mid = (L+R)/2;
    down(StId);
    if (st[StId*2 + 1].r < 2 )
        return OpenSolution(StId*2 + 1, mid + 1, R);
    else
        return OpenSolution(StId*2, L, mid);
}

void SolveTestCase() {
    int x, ChangeID;
    cin >> x;
    if (s[x] == '(') {
        s[x] = ')';
        update(1,1,l,x,-2);
        ChangeID = CloseSolution(1,1,l);
    }
    else {
        s[x] = '(';
        update(1,1,l,x,2);
        ChangeID = OpenSolution(1,1,l);
    }
    if (s[ChangeID] == '(') {
        s[ChangeID] = ')';
        update(1,1,l,ChangeID,-2);
    }
    else {
        s[ChangeID] = '(';
        update(1,1,l,ChangeID,2);
    }
    cout << ChangeID << '\n';
}

void Solve() {
    s = ' ' + s;
    l = s.length() - 1;
    for (int i = 1 ; i <= l ; i++)
        sum[i] = sum[i - 1] + ParenVal(i);
    build(1,1,l);
    for (int i = 1 ; i <= q ; i++)
        SolveTestCase();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    Solve();
    return 0;
}
