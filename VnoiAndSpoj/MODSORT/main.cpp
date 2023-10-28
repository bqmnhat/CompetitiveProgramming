#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll k, a[MaxN+1];
map<ll, ll> st;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void SolveTestCase() {
    st.clear();
    for (int i=1; i<=n; i++) {
        if (st[a[i]%k] > a[i]) {
            cout << "No\n";
            return;
        }
        st[a[i]%k] = a[i];
    }
    cout << "Yes\n";
}

void SolveSub1() {
    for (int i=1; i<n; i++) {
        if (a[i] > a[i+1]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        if (k == 1)
            SolveSub1();
        else
            SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
