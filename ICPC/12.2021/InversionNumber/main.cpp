#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1000001], cnt[1000001], cd[1000001];
pair<int,int> b[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].id = i;
    }
}

void Solve() {
    sort(b+1, b+1+n);
    int sum = n;
    for (int i=1; i<=n; i++) {
        cnt[a[i]] = sum - (n-a[i]+1);
        sum--;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
