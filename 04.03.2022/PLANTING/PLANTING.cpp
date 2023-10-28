#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int L, n, x[200001], x1[200001], ans[200001], MaxLen = 0;
map<int, int> be, ed;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        x1[i] = x[i];
    }
}

void MakeMaps() {
    int st, End = 0;
    sort(x1+1, x1+1+n);
    for (int i=1; i<=n; i++) {
        st = End;
        End = x1[i];
        be[End] = st;
        ed[st] = End;
        MaxLen = max(MaxLen, End - st);
    }
    ed[x1[n]] = L;
    be[L] = x1[n];
    MaxLen = max(MaxLen, L - x1[n]);
}

void Solve() {
    int la = 0;
    for (int i = n; i>=1; i--) {
        la++;
        ans[la] = MaxLen;
        int NewSt = be[x[i]], NewEd = ed[x[i]];
        be.erase(be.find(x[i]));
        ed.erase(ed.find(x[i]));
        be[NewEd] = NewSt;
        ed[NewSt] = NewEd;
        MaxLen = max(MaxLen, NewEd - NewSt);
    }
    for (int i=la; i>=1; i--)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PLANTING.INP", "r", stdin);
    freopen("PLANTING.OUT", "w", stdout);
    cin >> L >> n;
    ReadData();
    MakeMaps();
    Solve();
    return 0;
}
