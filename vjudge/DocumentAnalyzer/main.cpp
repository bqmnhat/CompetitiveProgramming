#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
int s[MaxN+1];
unordered_map<string, int> MarkS;
int t, n, total = 0;

vector<string> PreProcessStr(string s) {
    vector<string> ans;
    ans.clear();
    string tmp = "";
    int l = s.length();
    for (int i=0; i<l; i++) {
        if ((s[i] >= 'a') && (s[i] <= 'z'))
            tmp.push_back(s[i]);
        else {
            if (tmp.length() > 0) {
                ans.push_back(tmp);
                tmp = "";
            }
        }
    }
    if (tmp.length() > 0)
        ans.push_back(tmp);
    return ans;
}

void ReadData() {
    string tmps;
    n = 0;
    total = 0;
    while ((cin >> tmps) && (tmps != "END")) {
        vector<string> tmp = PreProcessStr(tmps);
        for (string x : tmp) {
            if (x.length() > 0) {
                n++;
                if (MarkS.find(x) == MarkS.end()) {
                    total++;
                    MarkS[x] = total;
                }
                s[n] = MarkS[x];
            }
        }
    }
}

bool Check(int WSize, int val, int& p, int &q) {
    int vis[MaxN+1];
    for (int i=1; i<=total; i++)
        vis[i] = 0;
    int cnt = 0;
    for (int i=1; i<=WSize; i++) {
        if (vis[s[i]] == 0)
            cnt++;
        vis[s[i]]++;
    }
    if (cnt == val) {
        p = 1;
        q = WSize;
        return true;
    }
    for (int i=WSize+1; i<=n; i++) {
        vis[s[i-WSize]]--;
        if (vis[s[i-WSize]] == 0)
            cnt--;
        if (vis[s[i]] == 0)
            cnt++;
        vis[s[i]]++;
        if (cnt == val) {
            p = i - WSize + 1;
            q = i;
            return true;
        }
    }
    return false;
}

void SolveTestCase() {
    int lo = 1, hi = n, AnsP, AnsQ;
    while (lo <= hi) {
        int mid = (lo + hi)/2, p, q;
        if (Check(mid, total, p, q)) {
            AnsP = p;
            AnsQ = q;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << AnsP << ' ' << AnsQ << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        MarkS.clear();
        ReadData();
        cout << "Document " << i << ": ";
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
