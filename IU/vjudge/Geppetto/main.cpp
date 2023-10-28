#include <iostream>
#include <bits/stdc++.h>
#define MaxM 400
using namespace std;
typedef pair<int, int> pii;
int n, m;
pii c[MaxM+1];

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> c[i].first >> c[i].second;
        c[i].first--;
        c[i].second--;
    }
}

bool Check(int Config) {
    for (int i=1; i<=m; i++)
        if (((Config & (1 << c[i].first)) != 0) && (((Config & (1 << c[i].second)) != 0)))
            return false;
    return true;
}

int Solution() {
    int ans = 0, MaxConfigVal = (1 << n);
    for (int Config=0; Config<MaxConfigVal; Config++)
        if (Check(Config))
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
