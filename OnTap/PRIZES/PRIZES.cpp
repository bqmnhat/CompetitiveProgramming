#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[100001], cd[100001], Left[100001], Right[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void MakeCD() {
    for (int i=1; i<=n; i++) {
        cd[i] = cd[i-1] + a[i];
    }
}

void MakeLeft() {
    for (int i=k; i<=n; i++) {
        Left[i] = max(Left[i-1], cd[i] - cd[i-k]);
    }
}

void MakeRight() {
    for (int i=n-k+1; i>=1; i--) {
        Right[i] = max(Right[i+1], cd[i+k-1] - cd[i-1]);
    }
}

long long Solution() {
    long long ans = 1e14 + 1;
    for (int i=1; i<=n-k+1; i++) {
        ans = min(ans, max(Left[i-1], Right[i+k]));
    }
    return ans;
}

int main()
{
    freopen("PRIZES.INP", "r", stdin);
    freopen("PRIZES.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    MakeCD();
    MakeLeft();
    MakeRight();
    cout << Solution();
    return 0;
}
