#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef long long ll;
int n;
const ll Base = 31, Mod = 1e9+11;
ll PowOfB[MaxN+1];
vector<ll> HashValCol[MaxN+1], HashValRow[MaxN+1];
string sCol[MaxN+1], sRow[MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> sCol[i];
}

void MakeRowStrings() {
    string tmp;
    for (int i = 0; i<n; i++) {
        tmp = "";
        for (int j=0; j<n; j++)
            tmp.push_back(sCol[j][i]);
        sRow[i] = tmp;
    }
}

vector<ll> GenHash(string s, bool MakePow) {
    int l = s.length();
    vector<ll> h(l+1, 0);
    PowOfB[0] = 1;
    for (int i=1; i<=l; i++) {
        h[i] = (((h[i-1] * Base)%Mod) + (s[i-1] - 'a' + 1LL))%Mod;
        if (MakePow)
            PowOfB[i] = (PowOfB[i-1]*Base)%Mod;
    }
    return h;
}

void GenAllHashCol() {
    HashValCol[0] = GenHash(sCol[0], true);
    for (int i=1; i<n; i++)
        HashValCol[i] = GenHash(sCol[i], false);
}

void GenAllHashRow() {
    HashValRow[0] = GenHash(sRow[0], true);
    for (int i=1; i<n; i++)
        HashValRow[i] = GenHash(sRow[i], false);
}

ll GetHashVal(const vector<ll>& h, int l, int r) {
    return (h[r+1] - (h[l] * PowOfB[r-l+1])%Mod + Mod)%Mod;
}

bool CheckSquare(int x, int y, int len) {
    int l = x, r = x+len-1;
    while (l < r) {
        if (GetHashVal(HashValRow[l], y, y+len-1) != GetHashVal(HashValRow[r], y, y+len-1))
            return false;
        l++;
        r--;
    }
    l = y, r = y+len-1;
    while (l < r) {
        if (GetHashVal(HashValCol[l], x, x+len-1) != GetHashVal(HashValCol[r], x, x+len-1))
            return false;
        l++;
        r--;
    }
    return true;
}

int Solution() {
    for (int len = n; len>=1; len--) {
        for (int i=0; i+len-1<n; i++) {
            for (int j=0; j+len-1<n; j++) {
                if (CheckSquare(i, j, len))
                    return len;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeRowStrings();
    GenAllHashCol();
    GenAllHashRow();
    cout << Solution();
    return 0;
}
// Cach hay hon la lam dp Goi dp[i][j][k] = true neu hinh vuong canh dai k dinh trai tren (i, j) la Palin Square.
// dp[i][j][k] = (dp[i+1][j+1][k-2] && (2 cot ngoai cung bang nhau) && (2 dong ngoai cung bang nhau))
