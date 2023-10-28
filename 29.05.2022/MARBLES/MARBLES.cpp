#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef pair<int, int> pii;
int n, a[MaxN+1];
multiset<int> pos[3];
string s;
pii Ranges[3];

void SplitData(string s) {
    for (int i=0; i<n; i++) {
        if (s[i] == 'X')
            a[i+1] = 0;
        else if (s[i] == 'T')
            a[i+1] = 1;
        else
            a[i+1] = 2;
        pos[a[i+1]].insert(i+1);
    }
}

void MakeRanges() {
    for (int i=0; i<3; i++) {
        int lo, hi;
        if (i == 0)
            lo = 1;
        else
            lo = Ranges[i-1].second + 1;
        hi = lo + pos[i].size() - 1;
        Ranges[i] = pii(lo, hi);
    }
}

bool InRange(int type, int id) {
    return ((Ranges[type].first <= id) && (id <= Ranges[type].second));
}

int Solution() {
    int NumSwap = 0;
    for (int i=0; i<3; i++) {
        int lo = Ranges[i].first, hi = Ranges[i].second;
        for (auto x: pos[i]) {
            if (InRange(i, x))
                continue;
            NumSwap++;
            int SwapWth = -1;
            for (int j=lo; j<=hi; j++) {
                if (a[j] != i) {
                    if (SwapWth == -1)
                        SwapWth = j;
                    else if (InRange(a[j], x))
                        SwapWth = j;
                }
            }
            pos[a[SwapWth]].erase(pos[a[SwapWth]].find(SwapWth));
            pos[a[SwapWth]].insert(x);
            swap(a[x], a[SwapWth]);
        }
    }
    return NumSwap;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MARBLES.INP", "r", stdin);
    freopen("MARBLES.OUT", "w", stdout);
    cin >> n >> s;
    SplitData(s);
    MakeRanges();
    cout << Solution();
    return 0;
}
