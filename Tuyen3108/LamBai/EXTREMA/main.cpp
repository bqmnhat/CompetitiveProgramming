#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
bool CucTri[MaxN+1];
int n, q, ans = 0, Pre, Nex;
ll a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void CountAnsFirst() {
    for (int i=2; i<n; i++) {
        if (((a[i] > max(a[i-1], a[i+1])) || (a[i] < min(a[i-1], a[i+1])))) {
            ans++;
            CucTri[i] = true;
        }
    }
}

void SolveQuerryT(ll ax, int Pre, int Nex, int x) {
    int tmpans = ans;
    if ((x > 1) && (x < n)) {
        if (((a[x] > max(a[x-1], a[x+1])) || (a[x] < min(a[x-1], a[x+1]))) && (!CucTri[x]))
            tmpans++;
        else if ((CucTri[x]) && (!((a[x] > max(a[x-1], a[x+1])) || (a[x] < min(a[x-1], a[x+1])))))
            tmpans--;
    }
    if ((Pre > 1) && (Pre < n)) {
        if (((a[Pre] > max(a[Pre-1], a[Pre+1])) || (a[Pre] < min(a[Pre-1], a[Pre+1]))) && (!CucTri[Pre]))
            tmpans++;
        else if ((CucTri[Pre]) && (!((a[Pre] > max(a[Pre-1], a[Pre+1])) || (a[Pre] < min(a[Pre-1], a[Pre+1])))))
            tmpans--;
    }
    if ((Nex > 1) && (Nex < n)) {
        if (((a[Nex] > max(a[Nex-1], a[Nex+1])) || (a[Nex] < min(a[Nex-1], a[Nex+1]))) && (!CucTri[Nex]))
            tmpans++;
        else if ((CucTri[Nex]) && (!((a[Nex] > max(a[Nex-1], a[Nex+1])) || (a[Nex] < min(a[Nex-1], a[Nex+1])))))
            tmpans--;
    }
    cout << tmpans << '\n';
    a[x] = ax;
}

void SolveQuerryP(int Pre, int Nex, int x) {
    if ((x > 1) && (x < n)) {
        if (((a[x] > max(a[x-1], a[x+1])) || (a[x] < min(a[x-1], a[x+1]))) && (!CucTri[x])) {
            ans++;
            CucTri[x] = true;
        }
        else if ((!((a[x] > max(a[x-1], a[x+1])) || (a[x] < min(a[x-1], a[x+1])))) && (CucTri[x])) {
            ans--;
            CucTri[x] = false;
        }
    }
    if ((Pre > 1) && (Pre < n)) {
        if (((a[Pre] > max(a[Pre-1], a[Pre+1])) || (a[Pre] < min(a[Pre-1], a[Pre+1]))) && (!CucTri[Pre])) {
            ans++;
            CucTri[Pre] = true;
        }
        else if ((!((a[Pre] > max(a[Pre-1], a[Pre+1])) || (a[Pre] < min(a[Pre-1], a[Pre+1])))) && (CucTri[Pre])) {
            ans--;
            CucTri[Pre] = false;
        }
    }
    if ((Nex > 1) && (Nex < n)) {
        if (((a[Nex] > max(a[Nex-1], a[Nex+1])) || (a[Nex] < min(a[Nex-1], a[Nex+1]))) && (!CucTri[Nex])) {
            ans++;
            CucTri[Nex] = true;
        }
        else if ((!((a[Nex] > max(a[Nex-1], a[Nex+1])) || (a[Nex] < min(a[Nex-1], a[Nex+1])))) && (CucTri[Nex])) {
            ans--;
            CucTri[Nex] = false;
        }
    }
    cout << ans << '\n';
}

void Solve() {
    for (int i=1; i<=q; i++) {
        char cmd;
        int x;
        ll y;
        cin >> cmd >> x >> y;
        ll ax = a[x];
        Pre = x - 1, Nex = x + 1;
        a[x] = y;
        if (cmd == 'P')
            SolveQuerryP(Pre, Nex, x);
        else
            SolveQuerryT(ax, Pre, Nex, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("EXTREMA.INP", "r", stdin);
    //freopen("EXTREMA.OUT", "w", stdout);
    cin >> n >> q;
    ReadData();
    CountAnsFirst();
    Solve();
    return 0;
}
