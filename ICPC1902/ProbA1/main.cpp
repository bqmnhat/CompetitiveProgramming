#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int Query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int y;
    cin >> y;
    return y;
}

inline void Solve() {
    int x, y, l = 1 , r = n;
    while (r > l) {
        int m = (l + r)/2;
        cout << "? " << l << ' ' << r << endl;
        cin >> x;
        if (x < m) {
            if (x != Query(l, m))
                l = m+1;
            else
                r = m;
        } else {
            if (x != Query(m, r))
                r = m-1;
            else
                l = m;
        }
    }
    cout << "! " << r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    Solve();
    return 0;
}
