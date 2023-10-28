#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, w, h;
long long hor1[200001], hor2[200001], ver1[200001], ver2[200001], Minhor1 = 1e9, Maxhor1 = 0, Minhor2 = 1e9, Maxhor2 = 0, Minver1 = 1e9, Maxver1 = 0, Minver2 = 1e9, Maxver2 = 0;
void ReadData() {
    int k;
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> hor1[i];
        if (hor1[i] < Minhor1)
            Minhor1 = hor1[i];
        if (hor1[i] > Maxhor1)
            Maxhor1 = hor1[i];
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> hor2[i];
        if (hor2[i] < Minhor2)
            Minhor2 = hor2[i];
        if (hor2[i] > Maxhor2)
            Maxhor2 = hor2[i];
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> ver1[i];
        if (ver1[i] < Minver1)
            Minver1 = ver1[i];
        if (ver1[i] > Maxver1)
            Maxver1 = ver1[i];
    }
    cin >> k;
    for (int i=1; i<=k; i++) {
        cin >> ver2[i];
        if (ver2[i] < Minver2)
            Minver2 = ver2[i];
        if (ver2[i] > Maxver2)
            Maxver2 = ver2[i];
    }
}

long long Solution() {
    long long S1 = (Maxhor1 - Minhor1)*h, S2 = (Maxhor2 - Minhor2)*h, S3 = (Maxver1 - Minver1)*w, S4 = (Maxver2 - Minver2)*w;
    long long ans = max(S1, S2);
    ans = max(ans, S3);
    ans = max(ans, S4);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> w >> h;
        Minhor1 = 1e9;
        Maxhor1 = 0;
        Minhor2 = 1e9;
        Maxhor2 = 0;
        Minver1 = 1e9;
        Maxver1 = 0;
        Minver2 = 1e9;
        Maxver2 = 0;
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
