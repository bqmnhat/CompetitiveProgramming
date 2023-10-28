#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, p;
struct Note {
    int s, f;
} x[500001];
vector <int> v[7];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i].s >> x[i].f;
    }
}

int MinChange() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        while ((!v[x[i].s].empty()) && (x[i].f < v[x[i].s].back())) {
            ans++;
            v[x[i].s].pop_back();
        }
        if ((v[x[i].s].empty()) || (x[i].f != v[x[i].s].back())) {
            ans++;
            v[x[i].s].push_back(x[i].f);
        }
    }
    return ans;
}

int main()
{
    freopen("GUITAR.INP", "r", stdin);
    freopen("GUITAR.OUT", "w", stdout);
    cin >> n >> p;
    ReadData();
    cout << MinChange();
    return 0;
}
