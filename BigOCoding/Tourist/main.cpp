#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, k, n, nxtID[51], visited[51];
long long v;
pair<long long, int> tk[51];
string a[51];

void Init() {
    for (int i=0; i<n; i++) {
        nxtID[i] = -1;
        visited[i] = -1;
        tk[i].second = i;
        tk[i].first = 0;
    }
}

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

void MakenxtID() {
    for (int i=0; i<n; i++)
        nxtID[i] = (i+k)%n;
}

bool CmpPair(pair<long long, int> a, pair<long long, int> b) {
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first > b.first);
}

void SolveTestCases() {
    long long CycleLength = n, CycleStart = 0;
    for (int i=1, p = 0; i<=n+1; i++) {
        if (visited[p] != -1) {
            CycleStart = p;
            CycleLength = i - visited[p];
            break;
        }
        visited[p] = i;
        p = nxtID[p];
    }
    long long p = 0;
    v = v%CycleLength;
    if (v == 0)
        v = CycleLength;
    p = CycleStart;
    for (int i=1; i<v; i++) {
        for (int i=1, x=p; i<=k; i++) {
            tk[x].first++;
            x = (x+1)%n;
        }
        p = nxtID[p];
    }
    pair<long long, int> ans[51];
    for (int i=1; i<=k; i++) {
        ans[i] = tk[p];
        p = (p+1)%n;
    }
    sort(ans+1, ans+1+k, CmpPair);
    for (int i=1; i<=k; i++) {
        cout << a[ans[i].second] << ' ';
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> v;
        Init();
        ReadData();
        MakenxtID();
        cout << "Case #" << i << ": ";
        SolveTestCases();
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
