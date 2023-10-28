#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, cnt[7], a[500001], Map[43];

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] = Map[a[i]];
    }
}

int Solution() {
    for (int i=1; i<=n; i++) {
        if (a[i] == 1) {
            cnt[1]++;
        }
        else if (cnt[a[i]-1] > 0) {
            cnt[a[i]]++;
            cnt[a[i]-1]--;
        }
    }
    return (n - 6*cnt[6]);
}

int main()
{
    Map[4] = 1;
    Map[8] = 2;
    Map[15] = 3;
    Map[16] = 4;
    Map[23] = 5;
    Map[42] = 6;
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
