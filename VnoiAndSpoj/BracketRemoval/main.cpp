#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, q;
string s;
vector<int> pos;

void MarkSimpleBrackets(string s) {
    for (int i=1; i<n; i++)
        if ((s[i] == ')') && (s[i-1] == '('))
            pos.push_back(i);
    pos.push_back(n);
}

int Query(int l, int r) {
    int L = upper_bound(pos.begin(), pos.end(), l) - pos.begin();
    int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
    return (R - L);
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << Query(l, r) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    MarkSimpleBrackets(s);
    Solve();
    return 0;
}
