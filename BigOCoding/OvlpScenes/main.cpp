#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n, a[7];
string s[7];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

string CombStr(string a, string b) {
    string Ans = a + b, MaxSame = "";
    int la = a.length(), lb = b.length(), cnt = 0;
    for (int k = 0; k<la; k++) {
        string tmp = "";
        bool FoundSame = false;
        for (int i = 0; i+k < la && i < lb; i++) {
            if (b[i] != a[i+k])
                break;
            else
                tmp = tmp + b[i];
            if (i + k == la - 1)
                FoundSame = true;
        }
        if ((FoundSame) && (tmp.length() > MaxSame.length())) {
            MaxSame = tmp;
            Ans = "";
            for (int i=0; i<k; i++)
                Ans = Ans + a[i];
            Ans = Ans + MaxSame;
            int lm = MaxSame.length();
            for (int i = lm; i<lb; i++)
                Ans = Ans + b[i];
        }
    }
    return Ans;
}

int MinLenOfFilm() {
    for (int i=1; i<=n; i++)
        a[i] = i;
    int MinLen = 1e9;
    string tmp = "";
    for (int i=1; i<=n; i++)
            tmp = CombStr(tmp, s[a[i]]);
    MinLen = tmp.length();
    while (next_permutation(a+1, a+1+n)) {
        tmp = "";
        for (int i=1; i<=n; i++)
            tmp = CombStr(tmp, s[a[i]]);
        MinLen = min(MinLen, (int)tmp.length());
    }
    return MinLen;
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n;
        ReadData();
        cout << "Case " << i << ": " << MinLenOfFilm() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    //cout << CombStr("ABCD", "CDEFGH");
    return 0;
}
