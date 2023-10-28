#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, lcs[1001][1001], lc = 0;
long long a[1001], b[1001], cube[300000];
bool Sieve[3000001];
string sx, sy;

bool CheckSquareNum(long long x) {
    long long tmp = sqrt(x);
    return (x == (tmp*tmp));
}

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    int tmp = sqrt(3000000);
    for (int i=2; i<=tmp; i++)
        if (Sieve[i] == false)
            for (int j=i; i*j <= 3000000; j++)
                Sieve[i*j] = true;
}

void MakeCube() {
    for (long long i=1; i<=3000000; i++) {
        if (!Sieve[i]) {
            lc++;
            cube[lc] = i*i*i;
        }
    }
}

bool CheckCubeNum(long long val) {
    int lo = 1, hi = lc;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (val == cube[m])
            return true;
        else if (val < cube[m])
            hi = m - 1;
        else
            lo = m + 1;
    }
    return false;
}

void SplitData(string s, long long a[1001], int &n) {
    long long x = 0;
    n = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] != ' ')
            x = x*10 + (s[i] - '0');
        else {
            if ((CheckSquareNum(x)) || (CheckCubeNum(x))) {
                n++;
                a[n] = x;
            }
            x = 0;
        }
    }
}

int FoundLCS() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i] == b[j])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    return lcs[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GEN.INP", "r", stdin);
    freopen("GEN.OUT", "w", stdout);
    MakeSieve();
    MakeCube();
    getline(cin, sx);
    getline(cin, sy);
    SplitData(sx, a, n);
    SplitData(sy, b, m);
    cout << '\0' << FoundLCS();
    return 0;
}
