#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a,b;

int DifChar(string x, char &c) {
    int lx = x.length();
    bool mark[257];
    for (int i=0; i<257; i++)
        mark[i] = false;
    int ans = 0;
    for (int i=0; i<lx; i++) {
        if (!mark[x[i]]) {
            ans++;
            mark[x[i]] = true;
            c = x[i];
        }
    }
    return ans;
}

long long Solution() {
    char cb;
    int lb = b.length(), la = a.length();
    bool bHaveOneC = (DifChar(b,cb) == 1);
    int ans = 0;
    for (int i=1; i<=lb; i++) {
        for (int j=0; j<la-lb+1; j++) {
            bool IsSub = true;
            for (int t=0; t<lb; t++) {
                if (a[j+t] != b[t]) {
                    IsSub = false;
                    break;
                }
            }
            if (IsSub)
                ans++;
        }
        if (bHaveOneC)
            break;
        b = b[lb-1] + b;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("STRINGS.INP", "r", stdin);
    freopen("STRINGS.OUT", "w", stdout);
    cin >> a >> b;
    char c1, c2;
    if (DifChar(a, c1) == 1) {
        if (DifChar(b, c2) == 1) {
            if (c1 == c2)
                cout << (a.length() - b.length() + 1);
            else
                cout << '0';
        }
        else
            cout << '0';
    }
    else
        cout << Solution();
    return 0;
}
