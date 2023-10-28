#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, a[MaxN+1], q, d;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

vector<int> MaxOfSubarrays(int d) {
    vector<int> ans;
    deque<int> dq;
    for (int i=1; i<=n; i++) {
        if ((!dq.empty()) && (dq.front() <= i - d))
            dq.pop_front();
        while ((!dq.empty()) && (a[dq.back()] <= a[i]))
            dq.pop_back();
        dq.push_back(i);
        if (i >= d)
            ans.push_back(a[dq.front()]);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> d;
        vector<int> ArrOfMax = MaxOfSubarrays(d);
        int ans = 1e9;
        for (auto x: ArrOfMax)
            ans = min(ans, x);
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
