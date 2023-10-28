#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100001], Left[100001], Right[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long GCD(long long a, long long b) {
    long long tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

void MakeLR() {
    Left[1] = a[1];
    Right[n] = a[n];
    for (int i=2; i<=n; i++) {
        Left[i] = GCD(Left[i-1], a[i]);
    }
    for (int i=n-1; i>=1; i--) {
        Right[i] = GCD(Right[i+1], a[i]);
    }
}

void MaxPoint() {
    long long ans = Right[2];
    int pos = 1;
    for (int i=2; i<n; i++) {
        long long m = GCD(Left[i-1], Right[i+1]);
        if (m > ans) {
            ans = m;
            pos = i;
        }
    }
    if (Left[n-1] > ans) {
        ans = Left[n-1];
        pos = n;
    }
    cout << pos << " " << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GCD.INP", "r", stdin);
    freopen("GCD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeLR();
    MaxPoint();
    return 0;
}
