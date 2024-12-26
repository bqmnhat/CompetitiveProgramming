#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int t, n, a[2*MaxN+5];
vector<int> Even, Odd;

void ReadData() {
    for (int i=1; i<=2*n; i++)
        cin >> a[i];
}

void Solve() {
    for (int i=1; i<=2*n; i++) {
        if (a[i]%2 == 0)
            Even.push_back(i);
        else
            Odd.push_back(i);
    }
    if (Even.size() % 2 != 0)
        Even.pop_back();
    if (Odd.size() % 2 != 0)
        Odd.pop_back();
    int cnt = 0;
    for (int i=0; i<Even.size() && cnt < n-1; i+=2) {
        cout << Even[i] << ' ' << Even[i+1] << '\n';
        cnt++;
    }
    for (int i=0; i<Odd.size() && cnt < n-1; i+=2) {
        cout << Odd[i] << ' ' << Odd[i+1] << '\n';
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        Even.clear();
        Odd.clear();
        ReadData();
        Solve();
    }
    return 0;
}
