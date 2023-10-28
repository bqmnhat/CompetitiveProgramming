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

long long Solution() {
    long long ans = 0, tmp = 0;
    sort(a+1, a+1+n);
    for (int i = 1; i<=n; i++) {
        if (a[i] == a[i+1]) {
            tmp++;
        }
        else {
            tmp++;
            if (tmp > 1)
                ans = ans + tmp*(tmp-1)/2;
            tmp = 0;
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
