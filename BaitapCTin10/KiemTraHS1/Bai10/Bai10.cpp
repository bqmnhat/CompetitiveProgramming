#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, MinDay = 1e9, MaxDay = 0;
pair<int,int> Ranges[100001];
priority_queue <int, vector<int>, greater<int>> pq;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> Ranges[i].first >> Ranges[i].second;
        if (Ranges[i].first < MinDay)
            MinDay = Ranges[i].first;
        if (Ranges[i].second > MaxDay)
            MaxDay = Ranges[i].second;
    }
}

int Solution() {
    sort(Ranges+1, Ranges+1+n);
    int j = 1, ans = 0;
    for (int i=MinDay; i<=MaxDay; i++) {
        while ((j <= n) && (Ranges[j].first <= i)) {
            pq.push(Ranges[j].second);
            j++;
        }
        while ((!pq.empty()) && (pq.top() < i))
            pq.pop();
        if (pq.empty())
            continue;
        ans++;
        pq.pop();
    }
    return ans;
}

int main()
{
    freopen("Bai10.INP", "r", stdin);
    freopen("Bai10.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
