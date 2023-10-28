#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
string a, b;
int na, nb;
int CntA[257], CntB[257];

vector<int> MakePrefFunction(string s) {
    int l = s.length();
    vector<int> p(l, 0);
    p[0] = 0;
    for (int i=1; i<l; i++) {
        p[i] = p[i-1];
        while ((p[i] > 0) && (s[p[i]] != s[i]))
            p[i] = p[p[i] - 1];
        if (s[p[i]] == s[i])
            p[i]++;
    }
    return p;
}

vector<int> MakeZFunction(string s) {
    int len = s.length(), l = 0, r = 0;
    vector<int> z(len, 0);
    for (int i=1; i<len; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < len) && (s[i+z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

bool CheckSame() {
    for (int i=0; i<na; i++)
        CntA[a[i]]++;
    for (int i=0; i<nb; i++)
        CntB[b[i]]++;
    for (int i=1; i<=256; i++)
        if (CntA[i] != CntB[i])
            return false;
    return true;
}

void Solve() {
    na = a.length();
    nb = b.length();
    reverse(a.begin(), a.end());
    if (a == b) {
        if (na == 1)
            cout << "-1 -1";
        else
            cout << na-2 << ' ' << na-1;
        return;
    }
    if (na != nb) {
        cout << "-1 -1";
        return;
    }
    if (!CheckSame()) {
        cout << "-1 -1";
        return;
    }
    string AB = a + char(31) + b;
    int AnsI = -1, AnsJ = -1;
    vector<int> pAB = MakePrefFunction(AB);
    reverse(a.begin(), a.end());
    string BA = b + char(31) + a;
    vector<int> zBA = MakeZFunction(BA);
    for (int i=0; i<na - 1; i++) {
        if (a[i] != b[na - i - 1])
            break;
        int len = pAB[2*na - i - 1];
        if (zBA[nb + i + 2] >= nb - i - len - 1) {
            AnsI = i;
            AnsJ = nb - len;
        }
    }
    cout << AnsI << ' ' << AnsJ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, a);
    getline(cin, b);
    Solve();
    return 0;
}
