#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> BigInt;
BigInt WayToTile[1001];

BigInt operator + (BigInt a, BigInt b) {
    BigInt ans;
    int i = 0, j = 0, tmp = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size()) {
            tmp += a[i];
            i++;
        }
        if (j < b.size()) {
            tmp += b[j];
            j++;
        }
        ans.push_back(tmp%10);
        tmp = tmp/10;
    }
    if (tmp > 0)
        ans.push_back(tmp);
    return ans;
}

BigInt operator * (int b, BigInt a) {
    BigInt ans;
    int tmp = 0;
    for (int i=0; i<a.size(); i++) {
        tmp = tmp + a[i]*b;
        ans.push_back(tmp%10);
        tmp = tmp/10;
    }
    if (tmp > 0)
        ans.push_back(tmp);
    return ans;
}

void PrintBigInt(BigInt a) {
    for (int i=a.size()-1; i>=0; i--)
        cout << a[i];
}

void FindWays() {
    WayToTile[0] = {1};
    WayToTile[1] = {1};
    for (int i=2; i<=1000; i++) {
        WayToTile[i] = 2*WayToTile[i-2] + WayToTile[i-1];
    }
}

void Solve() {
    int q;
    while (cin >> q) {
        PrintBigInt(WayToTile[q]);
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TILE.INP", "r", stdin);
    freopen("TILE.OUT", "w", stdout);
    FindWays();
    Solve();
    return 0;
}
