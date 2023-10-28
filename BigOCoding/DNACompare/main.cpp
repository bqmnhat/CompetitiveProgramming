#include <iostream>
#include <bits/stdc++.h>
#define MaxC 256
using namespace std;
string s, t;

void CountingSort(vector<int>& SA, vector<int>& RA, int k = 0) {
    int n = SA.size();
    vector<int> cnt(max(MaxC, n), 0);
    for (int i=0; i<n; i++) {
        if (i + k < n)
            cnt[RA[i+k]]++;
        else
            cnt[0]++;
    }
    for (int i=1; i<cnt.size(); i++)
        cnt[i] += cnt[i-1];
    vector<int> tmpSA(n);
    for (int i=n-1; i>=0; i--) {
        if (SA[i] + k < n)
            tmpSA[--cnt[RA[SA[i]+k]]] = SA[i];
        else
            tmpSA[--cnt[0]] = SA[i];
    }
    SA = tmpSA;
}

vector<int> ConstructSA(string s) {
    int n = s.length();
    vector<int> SA(n);
    vector<int> RA(n);
    vector<int> tmpRA(n);
    for (int i=0; i<n; i++) {
        RA[i] = s[i];
        SA[i] = i;
    }
    for (int step = 1; step < n; step <<= 1) {
        CountingSort(SA, RA, step);
        CountingSort(SA, RA, 0);
        tmpRA[SA[0]] = 0;
        for (int i=1; i<n; i++) {
            if((RA[SA[i]] == RA[SA[i-1]]) && (RA[SA[i] + step] == RA[SA[i-1]+step]))
                tmpRA[SA[i]] = tmpRA[SA[i-1]];
            else
                tmpRA[SA[i]] = tmpRA[SA[i-1]] + 1;
        }
        RA = tmpRA;
        if (RA[SA[n-1]] == n-1)
            break;
    }
    return SA;
}

vector<int> ConstructLCP(const string& s, const vector<int>& SA) {
    int n = SA.size(), sl = s.length();
    vector<int> LCP(n), PLCP(n), c(n, 0);
    for (int i=1; i<n; i++)
        c[SA[i]] = i;
    int k = 0, j;
    for (int i=0; i<n-1; i++) {
        int tmp = c[i] - 1;
        if (tmp == -1)
            continue;
        j = SA[tmp];
        k = max(0, k-1);
        while (s[i+k] == s[j+k])
            k++;
        PLCP[i] = k;
    }
    for (int i=0; i<n; i++)
        LCP[i] = PLCP[SA[i]];
    return LCP;
}

int Solution() {
    int tl = t.length();
    string tmp = t + '#' + s + '$';
    vector<int> SA = ConstructSA(tmp);
    vector<int> LCP = ConstructLCP(tmp, SA);
    int ans = 0;
    for (int i=1; i<LCP.size(); i++)
        if (((SA[i-1] < tl) && (SA[i] >= tl)) || ((SA[i-1] >= tl) && (SA[i] < tl)))
            ans = max(ans, LCP[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> s;
    cout << Solution();
    return 0;
}
