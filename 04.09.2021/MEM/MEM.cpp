#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 1000000
bool dd[MaxN+2];
int Min = 0, n;
string Q;

int QToInt() {
    int ans = 0;
    for (int i = 0; i<Q.length(); i++) {
        ans = ans*10 + (Q[i]-'0');
    }
    return ans;
}

void Solve() {
    if (Q == "?") {
        cout << Min << '\n';
        dd[Min] = true;
        while (dd[Min])
            Min++;
    }
    else {
        int m = QToInt();
        if (m <= MaxN)
            dd[m] = true;
        while (dd[Min])
            Min++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MEM.INP", "r", stdin);
    freopen("MEM.OUT", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> Q;
        Solve();
    }
    return 0;
}
