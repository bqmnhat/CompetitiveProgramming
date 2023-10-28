#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, pow2[21];
ll S, a1[21], a2[21], sum1 = 0, sum2 = 0, sl1 = 0, sl2 = 0, seg1[2000000], seg2[2000000], b[3][40];
ll freq1[2000000], freq2[2000000], f1 = 0, f2 = 0;

void ReadData() {
    int m = n/2;
    for (int i=0; i<m; i++) {
        cin >> a1[i];
    }
    m = n-m;
    for (int i=0; i<m; i++) {
        cin >> a2[i];
    }
}

ll NextSum(int t, ll a[21]) {
    int i = -1;
    ll ans = 0;
    while (t > 0) {
        i++;
        if ((t&1) == 1)
            ans = ans + a[i];
        t = (t >> 1);
    }
    return ans;
}

void GenSum() {
    int m = n/2, tmp = (1 << m);
    for (int i=1; i<tmp; i++) {
        sl1++;
        seg1[sl1] = NextSum(i, a1);
    }
    m = n-m;
    tmp = (1 << m);
    for (int i=1; i<tmp; i++) {
        sl2++;
        seg2[sl2] = NextSum(i, a2);
    }
}

int BinSearch(int lo, int hi, ll val) {
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (seg2[m] == val)
            return m;
        else if (seg2[m] < val)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

void MakeFreq() {
    sort(seg1+1, seg1+1+sl1);
    sort(seg2+1, seg2+1+sl2);
    freq1[0] = 1;
    for (int i=1; i<=sl1; i++) {
        if (seg1[i] != seg1[i-1]) {
            f1++;
            seg1[f1] = seg1[i];
        }
        freq1[f1]++;
    }
    freq2[0] = 1;
    for (int i=1; i<=sl2; i++) {
        if (seg2[i] != seg2[i-1]) {
            f2++;
            seg2[f2] = seg2[i];
        }
        freq2[f2]++;
    }
}

long long MaxVisit() {
    long long ans = 0;
    for (int i=0; i<=f1; i++) {
        if (S >= seg1[i]) {
            int tmp = BinSearch(0, f2, S - seg1[i]);
            if (tmp != -1) {
                ans = ans + (freq1[i]*freq2[tmp]);
            }
        }
    }
    if (ans == 0)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TRAVEL.INP", "r", stdin);
    freopen("TRAVEL.OUT", "w", stdout);
    cin >> n >> S;
    ReadData();
    GenSum();
    MakeFreq();
    cout << MaxVisit();
    return 0;
}
