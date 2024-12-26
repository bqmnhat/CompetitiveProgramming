// Bai tinh tong cua doan con. Build ST dang 2*MaxN
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100000
int n;
long long a[MaxN], st[2*MaxN];

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
}

void LoadST() {
    for (int i=n; i<2*n; i++) {
        st[i] = a[i-n];
    }
}

void BuildST() {
    for (int i=n-1; i>0; i--) {
        st[i] = st[2*i] + st[2*i+1]
    }
}

void modify(int p, int value) {
    p--;
    for (st[p += n] = value; p > 1; p >>= 1)
        st[p>>1] = st[p] + st[p^1];
}

long long query(int l, int r) {
    long long ans = 0;
    l--; r--;
    for (l += n, r += n; l<r; l>>=1, r>>=1) {
        if (l&1 == 1)
            ans += st[l++];
        if (r&1 == 0)
            ans += st[r--];
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int a,val,l,r;
        cin >> a >> val >> l >> r;
        for (int i=l; i<=r; i++) {
            modify(i,val)
        }
        cout << query(l,r);
    }
}

int main()
{
    cin >> n >> q;
    return 0;
}
