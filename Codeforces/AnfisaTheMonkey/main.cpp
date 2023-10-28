#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
string s;

void Solve() {
    n = s.length();
    int LineLen, Remain = 0;
    if (n%k == 0)
        LineLen = n/k;
    else {
        LineLen = n/k;
        Remain = n%k;
    }
    if ((LineLen < a) || (LineLen + (Remain > 0) > b) || (n < k)) {
        cout << "No solution";
        return;
    }
    int st = 0;
    while (st < n) {
        for (int i=st; i<st+LineLen & i < n; i++)
            cout << s[i];
        if (Remain > 0) {
            cout << s[st + LineLen];
            st++;
            Remain--;
        }
        cout << '\n';
        st += LineLen;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> a >> b >> s;
    Solve();
    return 0;
}
