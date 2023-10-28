#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
using namespace std;
typedef long long ll;
int n;
ll k, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int ans = 1e9;
    deque<int> dq;
    for (int i=1; i<=n; i++) {
        a[i] += a[i-1];
        if (a[i] >= k)
            ans = min(ans, i);
        while ((!dq.empty()) && (a[i] - a[dq.front()] >= k)) {
            ans = min(ans, i - dq.front());
            dq.pop_front();
        }
        while ((!dq.empty()) && (a[i] <= a[dq.back()]))
            dq.pop_back();
        dq.push_back(i);
    }
    if (ans == 1e9)
       return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
