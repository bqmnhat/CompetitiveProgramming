#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[100001], k, la = 1;
priority_queue <int, vector<int>, greater<int>> pq;

void ReadData() {
    while (cin >> a[la])
        la++;
    la--;
    k = a[la];
    la--;
    n = a[la];
    la--;
}

int Solution() {
    for (int i=1; i<=n; i++)
        pq.push(a[i]);
    for (int i=1; i<k; i++)
        pq.pop();
    return pq.top();
}

int main()
{
    freopen("Bai7.INP", "r", stdin);
    freopen("Bai7.OUT", "w", stdout);
    ReadData();
    cout << Solution();
    return 0;
}
