#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long b,mcdd[50001], mcdp[50001];
int n,m,k;
struct items {
    long long val;
    int ind;
}d[50001],p[50001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> d[i].val;
        d[i].ind = i;
    }
    for (int i=1; i<=m; i++) {
        cin >> p[i].val;
        p[i].ind = i;
    }
}

bool CompDec(items a, items b){
    return (a.val > b.val);
}

void MakeMCD() {
    for (int i=1; i<=n; i++)
        mcdd[i] = mcdd[i-1] + d[i].val;
    for (int i=1; i<=m; i++)
        mcdp[i] = mcdp[i-1] + p[i].val;
}

void Solve() {
    long long ans = 0;
    int  t = min(n,k),maxi = 0, maxj = 0,y;
    for (int x=0; x<=t; x++) {
        y = min(k-x,m);
        if ((b+mcdd[x])*(mcdp[y]+100) > ans) {
            maxi = x;
            maxj = y;
            ans = (b+mcdd[x])*(mcdp[y]+100);
        }
    }
    cout << maxi << " " << maxj << endl;
    for (int i = maxi; i>=1; i--)
        cout << d[i].ind << " ";
    cout << endl;
    for (int j = maxj; j>=1; j--)
        cout << p[j].ind << " ";
}

int main()
{
    freopen("VLTK.INP","r", stdin);
    freopen("VLTK.OUT","w", stdout);
    cin >> b >> k >> n >> m;
    ReadData();
    sort(p+1,p+1+m,CompDec);
    sort(d+1,d+1+n,CompDec);
    MakeMCD();
    Solve();
    return 0;
}
