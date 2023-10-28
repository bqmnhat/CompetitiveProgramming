#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, q, a[MaxN+1], PrefXor[MaxN+1], LastPos[MaxN+1];
ll pref[MaxN+1];
map<int, int> mEven, mOdd;

void ReadData() {
    mEven[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        PrefXor[i] = PrefXor[i-1]^a[i];
        pref[i] = pref[i-1] + ll(a[i]);
        if (i&1) {
            if (mEven.find(PrefXor[i]) != mEven.end())
                LastPos[i] = mEven[PrefXor[i]];
            mOdd[PrefXor[i]] = i;
        }
        else {
            if (mOdd.find(PrefXor[i]) != mOdd.end())
                LastPos[i] = mOdd[PrefXor[i]];
            mEven[PrefXor[i]] = i;
        }
    }
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        if ((PrefXor[r] ^ PrefXor[l-1]) != 0)
            cout << "-1";
        else if (pref[r] - pref[l-1] == 0)
            cout << "0";
        else if ((r-l+1)&1)
            cout << "1";
        else if ((a[l] == 0) || (a[r] == 0))
            cout << "1";
        else if (LastPos[r] >= l)
            cout << "2";
        else
            cout << "-1";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
