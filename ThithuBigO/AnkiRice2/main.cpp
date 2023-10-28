#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long MaxRice() {
    long long ans = 0, tmpmax, maxid;
    for (int i=1; i<=m; i++) {
        tmpmax = 0;
        for (int j=1; j<=n; j++) {
            if (a[j] > tmpmax) {
                tmpmax = a[j];
                maxid = j;
            }
        }
        ans += tmpmax;
        a[maxid] = (a[maxid] - 1)/2+1;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    ReadData();
    cout << MaxRice();
    return 0;
}
