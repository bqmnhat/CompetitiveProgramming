#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,a[101], MinID, MaxID;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            MinID = i;
        if (a[i] == n)
            MaxID = i;
    }
}

int Solution() {
    int ans1 = MinID + (n - MaxID + 1);
    int ans2 = MaxID + (n - MinID + 1);
    int ans3 = max(MaxID, MinID);
    int ans4 = n - min(MaxID, MinID) + 1;
    return min({ans1, ans2, ans3, ans4});
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
