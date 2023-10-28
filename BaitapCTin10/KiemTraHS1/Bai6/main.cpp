#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[100001];
priority_queue <int> pq;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int LastNum() {
    for (int i=1; i<=n; i++) {
        pq.push(a[i]);
    }
    while (pq.size() > 1) {
        int avg, num1,num2;
        num1 = pq.top();
        pq.pop();
        num2 = pq.top();
        pq.pop();
        avg = (num1 + num2 + 1)/2;
        pq.push(avg);
    }
    return pq.top();
}

int main()
{
    freopen("Bai6.INP", "r", stdin);
    freopen("Bai6.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << LastNum();
    return 0;
}
