#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, l = 0, q, freq[MaxN+1], pref[MaxN+1], log_2[MaxN+1], SpTabMaxFreq[MaxN+1][21];

void ReadData() {
    int PreAi = -1e9, ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai != PreAi)
            l++;
        freq[l]++;
        PreAi = ai;
    }
}

void MakePref() {
    for (int i=1; i<=l; i++)
        pref[i] = pref[i-1] + freq[i];
}

void MakeLog2() {
    log_2[1] = 0;
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2]+1;
}

void MakeSpTabMaxFreq() {
    for (int i=1; i<=l; i++)
        SpTabMaxFreq[i][0] = freq[i];
    int step;
    for (int j=1; (1 << j) <= l; j++) {
        step = (1 << (j-1));
        for (int i=1; i+2*step <= l+1; i++)
            SpTabMaxFreq[i][j] = max(SpTabMaxFreq[i][j-1], SpTabMaxFreq[i+step][j-1]);
    }
}

int GetMax(int lo, int hi) {
    if (lo > hi)
        return -1e9;
    int k = log_2[hi - lo + 1];
    return max(SpTabMaxFreq[lo][k], SpTabMaxFreq[hi - (1 << k) + 1][k]);
}

int BinSearchLowerBound(int val) {
    int lo = 0, hi = l, ans, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (pref[mid] <= val) {
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ans;
}

int BinSearchUpperBound(int val) {
    int lo = 0, hi = l, ans, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (pref[mid] >= val) {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return ans;
}

int SolutionForQuery(int lo, int ri) {
    int UBL = BinSearchUpperBound(lo), LBR = BinSearchLowerBound(ri);
    return max(min(pref[UBL], ri) - lo + 1, max(ri - max(pref[LBR], lo), GetMax(UBL+1, LBR)));
}

void SolveTestCases() {
    memset(freq, 0, sizeof(freq));
    memset(pref, 0, sizeof(pref));
    ReadData();
    MakePref();
    MakeSpTabMaxFreq();
    for (int i=1; i<=q; i++) {
        int lo, hi;
        cin >> lo >> hi;
        cout << SolutionForQuery(lo, hi) << '\n';
    }
}

void Solve() {
    MakeLog2();
    while (cin >> n >> q) {
        SolveTestCases();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
