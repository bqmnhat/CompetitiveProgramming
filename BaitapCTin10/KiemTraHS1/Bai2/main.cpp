#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100001];
priority_queue <ll> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int MaxLength() {
    ll SubSum = 0;
    for (int i=1; i<=n; i++) {
        SubSum += a[i];
        pq.push(a[i]);
        while (SubSum > 0) {
            SubSum = SubSum - pq.top();
            pq.pop();
        }
    }
    if (SubSum == 0)
        pq.pop();
    return  pq.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.INP", "r", stdin);
    freopen("Bai2.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MaxLength();
    return 0;
}
