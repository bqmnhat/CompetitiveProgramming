#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,S;
struct flower {
    int val,id;
} a[1000001], b[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i].val;
        b[i].id = i;
    }
}

int BinSearch(int p1) {
    int lo = 1, hi = m, ans = -1;
    while (lo <= hi) {
        int p2 = (lo+hi)/2;
        if (a[p1].val + b[p2].val<=S) {
            ans = p2;
            lo = p2+1;
        }
        else
            hi = p2-1;
    }
    return ans;
}

bool CmpVal(flower x, flower y) {
    return (x.val < y.val);
}

void Solve() {
    sort(a+1,a+1+n,CmpVal);
    sort(b+1,b+1+m,CmpVal);
    int ans1, ans2, sum;
    ans1 = 1;
    ans2 = BinSearch(1);
    sum = a[ans1].val + b[ans2].val;
    for (int i=2; i<=n; i++) {
        int tmp = BinSearch(i);
        if (tmp > 0) {
            if ((a[i].val + b[tmp].val > sum) or ((a[i].val + b[tmp].val == sum) && (abs(a[i].val - b[tmp].val) < abs(a[ans1].val - b[ans2].val)))) {
                ans1 = i;
                ans2 = tmp;
                sum = a[i].val + b[tmp].val;
            }
        }
    }
    if (ans2 == -1)
        cout << "0 0";
    else
        cout << a[ans1].id << " " << b[ans2].id;
}

int main()
{
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);
    cin >> n >> m >> S;
    ReadData();
    Solve();
    return 0;
}
