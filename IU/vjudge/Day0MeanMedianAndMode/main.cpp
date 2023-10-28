#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2500
#define MaxAi 100000
using namespace std;
int n, a[MaxN+1], cnt[MaxAi+1], sum = 0, FirstTimeExist[MaxAi+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void Solve() {
    double Mean = double(sum)/double(n);
    sort(a+1, a+1+n);
    double Med;
    if (n%2 == 1)
        Med = a[(n+1)/2];
    else
        Med = (a[n/2] + a[n/2 + 1])/2.00;
    int Mode = -1;
    for (int i=1; i<=n; i++) {
        cnt[a[i]]++;
        if (Mode == -1)
            Mode = a[i];
        else if ((cnt[a[i]] > cnt[Mode]) || ((cnt[a[i]] == cnt[Mode]) && (a[i] < Mode)))
            Mode = a[i];
    }
    cout << setprecision(1) << fixed << Mean << '\n' << Med << '\n' << Mode;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
