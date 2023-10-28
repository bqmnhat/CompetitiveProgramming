#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef long long ll;
int a[MaxN+5], k, n, t;
ll v;
unordered_map<int, string> ma;

void ReadData() {
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        ma[i] = s;
    }
}

bool IsNonDecreasing(int a[MaxN+5]) {
    for (int i=1; i<n; i++)
        if (a[i] > a[i+1])
            return false;
    return true;
}

void NextConfig(int a[MaxN+5]) {
    vector<int> tmp;
    tmp.clear();
    for (int i=1; i<=k; i++)
        tmp.push_back(a[i]);
    for (int i=1; i<=n-k; i++)
        a[i] = a[i+k];
    int id = 0;
    for (int i=n-k+1; i<=n; i++) {
        a[i] = tmp[id];
        id++;
    }
}

int FindCycle(int n) {
    for (int i=1; i<=n; i++)
        a[i] = i;
    int cnt = 0;
    do {
        cnt++;
        NextConfig(a);
    } while (!IsNonDecreasing(a));
    return cnt;
}

void SolveTestCase() {
    ll CycleLen = FindCycle(n);
    ll Remain = (v-1LL)%CycleLen;
    while (Remain) {
        NextConfig(a);
        Remain--;
    }
    vector<int> ansId;
    ansId.clear();
    for (int i=1; i<=k; i++)
        ansId.push_back(a[i]);
    sort(ansId.begin(), ansId.end());
    for (int id: ansId)
        cout << ma[id] << ' ';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> v;
        ma.clear();
        ReadData();
        cout << "Case #" << i << ": ";
        SolveTestCase();
        cout << '\n';
    }
}

int main()
{
    freopen("tourist_input.txt", "r", stdin);
    freopen("tourist_output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
