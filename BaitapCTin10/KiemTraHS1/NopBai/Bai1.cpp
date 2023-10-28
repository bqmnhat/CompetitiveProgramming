#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
pair<ll,ll> workers[100001];
priority_queue <ll, vector<ll>, greater<ll>> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> workers[i].second;
    for (int i=1; i<=n; i++)
        cin >> workers[i].first;
}

long long MaxAns() {
    long long ans = 0, SumSpeed = 0;
    sort(workers+1, workers+1+n);
    for (int i=n; i>=1; i--) {
        long long e = workers[i].first, s = workers[i].second;
        SumSpeed += s;
        pq.push(s);
        if (pq.size() > k) {
            long long tmp = pq.top();
            SumSpeed = SumSpeed - tmp;
            pq.pop();
        }
        ans = max(ans, SumSpeed*e);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.INP", "r", stdin);
    freopen("Bai1.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> k;
    cout << MaxAns();
    return 0;
}
