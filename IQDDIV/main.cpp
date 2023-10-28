#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, lx1 = -1, lx2 = -1;
long long a[32], x1[100000], x2[100000], sum = 0, f1[100000], f2[100000];

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void Compress(ll x[100000], ll f[100000], int &lx) {
    int l = 0;
    f[0] = 1;
    for (int i=1; i<=lx; i++) {
        if (x[i] != x[i-1]) {
            l++;
            f[l] = 1;
            x[l] = x[i];
        }
        else
            f[l]++;
    }
    lx = l;
}

ll NextBit(int num, int Disp) {
    ll ans = 0;
    int cnt = 0;
    while (num > 0) {
        ll tmp = (num&1);
        if (tmp == 1)
            ans = ans + a[cnt + Disp];
        num = (num >> 1);
        cnt++;
    }
    return ans;
}

void MakeX12() {
    int x = n/2;
    int tmp = (1<<x);
    for (int i=0; i < tmp; i++) {
        lx1++;
        x1[lx1] = NextBit(i, 0);
    }
    x = n - (n/2);
    tmp = (1<<x);
    for (int i=0; i<tmp; i++) {
        lx2++;
        x2[lx2] = NextBit(i, n/2);
    }
}

ll BinSearch1(ll val, int lo, int hi) {
    ll ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if ((sum - 2*(val + x2[m])) >= 0) {
            ans = m;
            lo = m+1;
        }
        else
            hi = m-1;
    }
    return ans;
}

ll BinSearch2(ll val, int lo, int hi) {
    ll ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if ((2*(val + x2[m]) - sum) >= 0) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

void Solve() {
    ll ChenhLech = 1e11, cnt = 0;
    sort(x1, x1+lx1+1);
    sort(x2, x2+lx2+1);
    Compress(x1,f1,lx1);
    Compress(x2,f2,lx2);
    for (int i=0; i<=lx1; i++) {
        ll tmp1 = BinSearch1(x1[i], 0, lx2);
        ll tmp2 = BinSearch2(x1[i], 0, lx2);
        if (tmp1 != -1) {
            ll tmpLech = abs(sum - 2*(x1[i] + x2[tmp1]));
            if (tmpLech == ChenhLech)
                cnt += (f2[tmp1]*f1[i]);
            else if (tmpLech < ChenhLech) {
                cnt = f2[tmp1]*f1[i];
                ChenhLech = tmpLech;
            }
        }
        if ((tmp2 != -1) && (tmp1 != tmp2)) {
            ll tmpLech = abs(sum - 2*(x1[i] + x2[tmp2]));
            if (tmpLech == ChenhLech)
                cnt += (f2[tmp2]*f1[i]);
            else if (tmpLech < ChenhLech) {
                cnt = f2[tmp2]*f1[i];
                ChenhLech = tmpLech;
            }
        }
    }
    cout << ChenhLech << " " << cnt/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeX12();
    Solve();
    return 0;
}
