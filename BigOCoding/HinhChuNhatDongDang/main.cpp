#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
double Rat[100001];
pii rec[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> rec[i].first >> rec[i].second;
        if (rec[i].second < rec[i].first)
            swap(rec[i].first, rec[i].second);
    }
}

void Solve() {
    int NumOfGr = 0, MaxRecInGr = 0, tmp = 0;
    for (int i=1; i<=n; i++)
        Rat[i] = double(double(rec[i].first)/double(rec[i].second));
    sort(Rat + 1, Rat + 1 + n);
    for (int i=1; i<=n; i++) {
        if (Rat[i] != Rat[i-1]) {
            NumOfGr++;
            tmp = 1;
        }
        else
            tmp++;
        MaxRecInGr = max(MaxRecInGr, tmp);
    }
    cout << NumOfGr << ' ' << MaxRecInGr;
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
