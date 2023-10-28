#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t;
long long sum;
priority_queue <long long, vector<long long>, greater<long long>> q;

void ReadData() {
    long long ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        sum += ai;
        q.push(ai);
    }
}

long long Solution() {
    if (n == 1)
        return 0;
    if (n == 2)
        return sum;
    long long ans = 0;
    while (q.size() > 1) {
        long long min1 = q.top();
        q.pop();
        long long min2 = q.top();
        q.pop();
        long long tmp = min1+min2;
        ans = ans + tmp;
        q.push(tmp);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        sum = 0;
        ReadData();
        cout << Solution() << '\n';
        while (!q.empty())
            q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
