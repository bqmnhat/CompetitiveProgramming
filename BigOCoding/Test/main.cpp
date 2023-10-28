#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s[4];
int p[4];
vector<int> a[4];

void InitP() {
    for (int i=1; i<=3; i++)
        p[i] = i;
}

void SplitData() {
    for (int i=1; i<=3; i++) {
        int tmp = s[i].length();
        for (int j=0; j<tmp; j++)
            a[i].push_back(s[i][j] - 'a' + 1);
    }
}

vector<int> MakeZFunction(const vector<int>& s) {
    int n = s.size();
    vector<int> z(n+1, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[i + z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int SamePrefAndSuf(const vector<int>& s1,const vector<int>& s2) {
    int s1len = s1.size();
    vector<int> tmp = s1;
    tmp.push_back(100);
    for (auto x: s2)
        tmp.push_back(x);
    int tmplen = tmp.size();
    vector<int> z = MakeZFunction(tmp);
    int ans = 0;
    for (int i=s1len+1; i<tmplen; i++)
        if ((i + z[i] == tmplen) || (z[i] == s1len))
            ans = max(ans, z[i]);
    return ans;
}

int Solution() {
    int ans = 1e9;
    do {
        int tmpans = a[p[1]].size();
        vector<int> Pre = a[p[1]], Cur;
        for (int i=2; i<=3; i++) {
            Cur = a[p[i]];
            int tmp = SamePrefAndSuf(Cur, Pre);
            tmpans += Cur.size() - tmp;
            int CurLen = Cur.size();
            for (int i=tmp; i<CurLen; i++)
                Pre.push_back(Cur[i]);
        }
        ans = min(ans, tmpans);
    } while (next_permutation(p+1, p+4));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    InitP();
    cin >> s[1] >> s[2] >> s[3];
    SplitData();
    cout << Solution();
    return 0;
}
