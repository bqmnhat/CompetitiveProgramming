#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n, k, m, grId[MaxN+5];
struct Apple {
    ll w;
    int IniId;
} a[MaxN+5];

void ReadData() {
    m = n/k;
    for (int i=1; i<=n; i++) {
        cin >> a[i].w;
        a[i].IniId = i;
    }
}

bool CmpAppleW(Apple a, Apple b) {
    if (a.w == b.w)
        return (a.IniId < b.IniId);
    return (a.w > b.w);
}

void FindValInGroups() {
    sort(a+1, a+1+n, CmpAppleW);
    for (int i=1; i<=n; i++) {
        int CurGr = (i-1)/k + 1;
        grId[a[i].IniId] = CurGr;
    }
}

int LIS(int a[MaxN+5]) {
    vector<int> LIS;
    for (int i=1; i<=n; i++) {
        int j = upper_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        if (j == LIS.size())
            LIS.push_back(a[i]);
        else
            LIS[j] = a[i];
    }
    return LIS.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("APROBOT.INP", "r", stdin);
    freopen("APROBOT.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    FindValInGroups();
    cout << n - LIS(grId);
    return 0;
}
