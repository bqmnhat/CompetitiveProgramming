#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
bool CucTri[MaxN+1];
int n, q, ans = 0;
ll a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool IsCucTri(int i) {
    return (((a[i] > a[i-1]) && (a[i] > a[i+1])) || ((a[i] < a[i-1]) && (a[i] < a[i+1])));
}

void CountAnsFirst() {
    for (int i=2; i<n; i++) {
        if (IsCucTri(i)) {
            ans++;
            CucTri[i] = true;
        }
    }
}

void SolveQuerryT(int x, ll y) {
    int Pre = x - 1, Nex = x + 1, tmpans = ans;
    ll ax = a[x];
    a[x] = y;
    if ((x != 1) && (x != n)) {
        if ((IsCucTri(x)) && (!CucTri[x]))
            tmpans++;
        if ((CucTri[x]) && (!IsCucTri(x)))
            tmpans--;
    }
    if ((Pre != 1) && (Pre != n)) {
        if ((IsCucTri(Pre)) && (!CucTri[Pre]))
            tmpans++;
        if ((CucTri[Pre]) && (!IsCucTri(Pre)))
            tmpans--;
    }
    if ((Nex != 1) && (Nex != n)) {
        if ((IsCucTri(Nex)) && (!CucTri[Nex]))
            tmpans++;
        if ((CucTri[Nex]) && (!IsCucTri(Nex)))
            tmpans--;
    }
    cout << tmpans << '\n';
    a[x] = ax;
}

void SolveQuerryP(int x, ll y) {
    int Pre = x - 1, Nex = x + 1;
    a[x] = y;
    if ((x != 1) && (x != n)) {
        if ((IsCucTri(x)) && (!CucTri[x])) {
            ans++;
            CucTri[x] = true;
        }
        if ((!IsCucTri(x)) && (CucTri[x])) {
            ans--;
            CucTri[x] = false;
        }
    }
    if ((Pre != 1) && (Pre != n)) {
        if ((IsCucTri(Pre)) && (!CucTri[Pre])) {
            ans++;
            CucTri[Pre] = true;
        }
        if ((!IsCucTri(Pre)) && (CucTri[Pre])) {
            ans--;
            CucTri[Pre] = false;
        }
    }
    if ((Nex != 1) && (Nex != n)) {
        if ((IsCucTri(Nex)) && (!CucTri[Nex])) {
            ans++;
            CucTri[Nex] = true;
        }
        if ((!IsCucTri(Nex)) && (CucTri[Nex])) {
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
        if (cmd == 'P')
            SolveQuerryP(x, y);
        else
            SolveQuerryT(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("EXTREMA.INP", "r", stdin);
    freopen("EXTREMA.OUT", "w", stdout);
    cin >> n >> q;
    ReadData();
    CountAnsFirst();
    Solve();
    return 0;
}
