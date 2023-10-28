#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define Mod 9
using namespace std;
int n, m, w, t, Pref[MaxN+1];
string s;
vector<int> MultMod[Mod][Mod], MinuMod[Mod][Mod];

void CalPref() {
    Pref[0] = (s[0] - '0')%Mod;
    for (int i=1; i<n; i++)
        Pref[i] = (Pref[i-1] + (s[i] - '0'))%Mod;
}

void CalMultAndMinu() {
    for (int i=0; i<Mod; i++) {
        for (int j=0; j<Mod; j++) {
            MultMod[i][j].clear();
            MinuMod[i][j].clear();
        }
    }
    for (int i=w-1; i<n; i++) {
        int Val;
        if (i != w - 1)
            Val = (Pref[i] - Pref[i - w] + Mod)%Mod;
        else
            Val = Pref[i]%Mod;
        for (int x=0; x<Mod; x++) {
            int tmpMult = (Val*x)%Mod, tmpMinu = (x - Val + Mod)%Mod;
            MultMod[x][tmpMult].push_back(i - w + 1);
            MinuMod[x][tmpMinu].push_back(i - w + 1);
        }
    }
}

void SolveTestCases() {
    for (int i=1; i<=m; i++) {
        int l, r, k, ans1 = 1e9, ans2 = 1e9;
        cin >> l >> r >> k;
        l--;
        r--;
        int a;
        if (l == 0)
            a = Pref[r];
        else
            a = (Pref[r] - Pref[l-1] + Mod)%Mod;
        for (int x=0; x<Mod; x++) {
            for (int j=0; j<2; j++) {
                if ((j < MultMod[a][x].size()) && (MultMod[a][x].size() > 0)) {
                    if (MultMod[a][x][j] < ans1) {
                        int i = 0;
                        while ((i < MinuMod[k][x].size()) && (MinuMod[k][x][i] == MultMod[a][x][j]))
                            i++;
                        if (i < MinuMod[k][x].size()) {
                            ans1 = MultMod[a][x][j];
                            ans2 = MinuMod[k][x][i];
                        }
                    }
                }
            }
        }
        ans1++;
        ans2++;
        if ((ans1 < 1e9) && (ans2<1e9))
            cout << ans1 << ' ' << ans2 << '\n';
        else
            cout << "-1 -1\n";
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        n = s.length();
        cin >> w >> m;
        CalPref();
        CalMultAndMinu();
        SolveTestCases();
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
