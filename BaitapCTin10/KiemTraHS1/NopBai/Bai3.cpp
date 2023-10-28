#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,W,k;
struct Project {
    long long profit, capital;
} pro[100001];
priority_queue <long long> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> pro[i].profit;
    for (int i=1; i<=n; i++) {
        cin >> pro[i].capital;
    }
}

bool ProCmp(Project a, Project b) {
    if (a.capital == b.capital)
        return (a.profit > b.profit);
    return (a.capital < b.capital);
}

long long MaxCap() {
    sort(pro+1, pro+1+n, ProCmp);
    int i = 1;
    while (k > 0) {
        while ((i <= n) && (pro[i].capital <= W)) {
            pq.push(pro[i].profit);
            i++;
        }
        if (!pq.empty()) {
            W = W + pq.top();
            pq.pop();
        }
        k--;
    }
    return W;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.INP", "r", stdin);
    freopen("Bai3.OUT", "w", stdout);
    cin >> n >> W >> k;
    ReadData();
    cout << MaxCap();
    return 0;
}
