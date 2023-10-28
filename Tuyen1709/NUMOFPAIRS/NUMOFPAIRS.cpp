#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
#define MaxVal 1000000
using namespace std;
int n, cntNum[MaxVal + 1], cntlen[MaxN+1], a[MaxN+1]; //stGCD[4*MaxN+1];
vector<int> pos[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

/*void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        stGCD[v] = a[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        stGCD[v] = __gcd(stGCD[v*2], stGCD[v*2+1]);
    }
}

int GetGCD(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return stGCD[v];
    int tm = ((tl + tr) >> 1);
    return __gcd(GetGCD(v*2, tl, tm, l, r), GetGCD(v*2+1, tm+1, tr, l, r));
}*/

void Solve() {
    for (int i=1; i<=n; i++) {
        int j, t;
        for (j=i-1; j>=1; j--)
            if (a[j]%a[i] !=0)
                break;
        j++;
        for (t=i+1; t<=n; t++)
            if (a[t]%a[i] != 0)
                break;
        t--;
        cntlen[t - j]++;
        pos[t-j].push_back(j);
    }
    int ans;
    for (int i=n; i>=0; i--) {
        if (cntlen[i] > 0) {
            ans = i;
            break;
        }
    }
    sort(pos[ans].begin(), pos[ans].end());
    int cnt = 0;
    for (int i=0; i<pos[ans].size(); i++)
        if ((i == 0) || ((i > 0) && (pos[ans][i] != pos[ans][i-1])))
            cnt++;
    cout << cnt << ' ' << ans << '\n';
    for (int i=0; i<pos[ans].size(); i++)
        if ((i == 0) || ((i > 0) && (pos[ans][i] != pos[ans][i-1])))
            cout << pos[ans][i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("NUMOFPAIRS.INP", "r", stdin);
    freopen("NUMOFPAIRS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
