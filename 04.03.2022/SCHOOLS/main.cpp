#include <iostream>
#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;
typedef long long ll;
struct City {
    ll a,b,diff;
} c[MAXN + 1];
int n, m, s;
ll L[MAXN + 1], R[MAXN + 2];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i].a >> c[i].b;
        c[i].diff = c[i].b - c[i].a;
    }
}

bool CmpCity(City a, City b) {
    return (a.diff < b.diff);
}

ll Solution() {
    sort(c+1, c+1+n, CmpCity);
    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        if (pq.size() < m) {
            L[i] = L[i-1] + c[i].a;
            pq.push(c[i].a);
        }
        else {
            pq.push(c[i].a);
            L[i] = L[i-1] + c[i].a - pq.top();
            pq.pop();
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i=n; i>=1; i--) {
        if (pq2.size() < s) {
            R[i] += R[i+1] + c[i].b;
            pq2.push(c[i].b);
        }
        else {
            pq2.push(c[i].b);
            R[i] = R[i+1] + c[i].b - pq2.top();
            pq2.pop();
        }
    }
    for (int i=m; i<=n-s; i++)
        ans = max(ans, L[i] + R[i+1]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SCHOOLS.INP", "r", stdin);
    freopen("SCHOOLS.OUT", "w", stdout);
    cin >> n >> m >> s;
    ReadData();
    cout << Solution();
    return 0;
}
