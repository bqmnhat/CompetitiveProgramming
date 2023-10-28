#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long GCD(long long a, long long b) {
    long long r;
    while (b != 0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

long long LCM(long long a, long long b) {
    return (a*b)/GCD(a,b);
}

int Solution() {
    int ans = 0;
    for (int i = 1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (a[i] + a[j] == 2*(LCM(a[i], a[j]))) {
                ans++;
                cout << a[i] << " " << a[j];
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
