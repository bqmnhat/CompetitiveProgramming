#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

void PrintBin(int k) {
    int la = 0;
    while (k > 0) {
        int tmp = (k&1);
        k = (k>>1);
        la++;
        if (tmp == 1)
            s[n - la] = '1';
        else
            s[n - la] = '0';
    }
}

void Solve() {
    int tmp = (1<<n);
    for (int i=0; i<tmp; i++) {
        PrintBin(i);
        cout << s << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BSTR.INP", "r", stdin);
    freopen("BSTR.OUT", "w", stdout);
    cin >> n;
    s = "";
    for (int i = 1; i <= n; i++)
        s.push_back('0');
    Solve();
    return 0;
}
