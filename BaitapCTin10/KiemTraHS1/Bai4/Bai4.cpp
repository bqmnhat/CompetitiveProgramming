#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100001],n;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Method1() {
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
}

void Method2() {
    priority_queue<int> pq(a+1, a+1+n);
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai4.INP", "r", stdin);
    freopen("Bai4.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Method1();
    Method2();
    return 0;
}
