#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int n, k, a[MaxN+1], t;
deque<int> dq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void SolveTestCases() {
    for (int i=1; i<=n; i++) {
        if ((!dq.empty()) && (dq.front() <= i - k))
            dq.pop_front();
        while ((!dq.empty()) && (a[dq.back()] <= a[i]))
            dq.pop_back();
        dq.push_back(i);
        if (i >= k)
            cout << a[dq.front()] << ' ';
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        SolveTestCases();
        cout << '\n';
        dq.clear();
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
