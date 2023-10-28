#include <iostream>
#include <bits/stdc++.h>
#define MaxC 256
using namespace std;
typedef long long ll;
int t;
string s1, s2;

void CountingSort(vector<int>& SA, vector<int>& RA, int k = 0) {
    int n = SA.size();
    vector<int> cnt(max(n, MaxC), 0);
    for (int i = 0; i<n; i++) {
        if (i + k < n)
            cnt[RA[i + k]]++;
        else
            cnt[0]++;
    }
    for (int i=1; i<cnt.size(); i++)
        cnt[i] += cnt[i-1];
    vector<int> tmpSA(n, 0);
    for (int i=n-1; i>=0; i--) {
        if (SA[i] + k < n)
            tmpSA[--cnt[RA[SA[i] + k]]] = SA[i];
        else
            tmpSA[--cnt[0]] = SA[i];
    }
    SA = tmpSA;
}

vector<int> ConstructSA(string s) {
    int n = s.length();
    vector<int> SA(n), RA(n), tmpRA(n);
    for (int i=0; i<n; i++) {
        SA[i] = i;
        RA[i] = int(s[i]);
    }
    for (int step = 1; step < n; step <<= 1) {
        CountingSort(SA, RA, step);
        CountingSort(SA, RA, 0);
        tmpRA[SA[0]] = 0;
        for (int i=1; i<n; i++) {
            if ((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i] + step] == RA[SA[i-1] + step]))
                tmpRA[SA[i]] = tmpRA[SA[i-1]];
            else
                tmpRA[SA[i]] = tmpRA[SA[i-1]]+1;
        }
        RA = tmpRA;
        if (RA[SA[n-1]] == n-1)
            break;
    }
    return SA;
}

vector<int> computeLCP(const string& s, const vector<int>& SA) {
    int n = SA.size();
    vector<int> LCP(n), PLCP(n), c(n, 0);
    for (int i=0; i<n; i++)
        c[SA[i]] = i;
    int k = 0, j;
    for (int i=0; i<n-1; i++) {
        k = max(k-1, 0);
        j = SA[c[i] - 1];
        while (s[i+k] == s[j+k])
            k++;
        PLCP[i] = k;
    }
    for (int i=0; i<n; i++)
        LCP[i] = PLCP[SA[i]];
    return LCP;
}

void SolveTestCase() {
    s1 = s1 + "$";
    s2 = s2 + "$";
    vector<int> SAs1 = ConstructSA(s1), SAs2 = ConstructSA(s2);
    vector<int> LCPs1 = computeLCP(s1, SAs1), LCPs2 = computeLCP(s2, SAs2);
    ll n1 = s1.length(), n2 = s2.length();
    ll cnts1 = (n1*(n1-1LL))/2, cnts2 = (n2*(n2 - 1LL))/2;
    for (int x: LCPs1)
        cnts1 -= 1LL*x;
    for (int x: LCPs2)
        cnts2 -= 1LL*x;
    if (cnts1 == cnts2)
        cout << "s\n";
    else
        cout << "n\n";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s1 >> s2;
        SolveTestCase();
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
