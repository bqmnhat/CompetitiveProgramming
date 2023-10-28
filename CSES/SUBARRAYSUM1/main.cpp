#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long x, a[200001];
queue<long long> q;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int CountSub() {
    int ans = 0;
    long long sum = 0;
    int i = 0;
    while (i<=n) {
        if (sum < x) {
            i++;
            sum += a[i];
            q.push(a[i]);
        }
        else if (sum > x) {
            sum = sum - q.front();
            q.pop();
        }
        else {
            ans++;
            sum = sum - q.front();
            q.pop();
        }
    }
    return ans;
}

int main()
{
    cin >> n >> x;
    ReadData();
    cout << CountSub();
    return 0;
}
