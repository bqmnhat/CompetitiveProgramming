#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n, digits[11], ld = 0, trace[MaxN+1], FormFrom[MaxN+1];
string s;
bool vis[MaxN+1];

void SplitIntoDigits(string s) {
    int l = s.length();
    for (int i=0; i<l; i++) {
        ld++;
        digits[ld] = s[i] - '0';
    }
}

bool BFS() {
    queue<int> q;
    for (int i=1; i<=ld; i++) {
        if (digits[i] == 0)
            continue;
        trace[digits[i]%n] = -1;
        vis[digits[i]%n] = true;
        FormFrom[digits[i]%n] = digits[i];
        q.push(digits[i]%n);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 0)
            return true;
        for (int i=1; i<=ld; i++) {
            int v = (u*10 + digits[i])%n;
            if (!vis[v]) {
                vis[v] = true;
                trace[v] = u;
                FormFrom[v] = digits[i];
                q.push(v);
            }
        }
    }
    return false;
}

void Solve() {
    SplitIntoDigits(s);
    bool CanFind = BFS();
    vector<int> ans;
    if (!CanFind)
        cout << '0';
    else {
        int u = 0;
        while (u != -1) {
            ans.push_back(FormFrom[u]);
            u = trace[u];
        }
        reverse(ans.begin(), ans.end());
        for (int x : ans)
            cout << x;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LM.INP", "r", stdin);
    freopen("LM.OUT", "w", stdout);
    cin >> n >> s;
    Solve();
    return 0;
}
