#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t;
long long a[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void ReverseData() {
    int i=1, j = n;
    while (i <= j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

long long MaxJumps() {
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        if (i - a[i] > 0)
            a[i] = a[i] + a[i - a[i]];
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        ReverseData();
        cout << MaxJumps() << '\n';
    }
    return 0;
}
