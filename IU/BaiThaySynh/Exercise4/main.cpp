// in ra tat ca cac cach doi gia tri k bang n LOAI tien (khong phai TO tien)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a, coins;
ll k;
bool Flag;

void ReadData() {
    ll ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        a.push_back(ai);
    }
}

void PrintAns(const vector<ll>& Coins) {
    for (auto x: Coins)
        cout << x << ' ';
    cout << '\n';
}

void PayMoney(int i, ll cost, vector<ll>& Coins) {
    if (cost == 0) {
        Flag = true;
        PrintAns(Coins);
        return;
    }
    if ((cost < 0) || ((i <= 0) && (cost > 0)))
        return;
    PayMoney(i-1, cost, Coins);
    Coins.push_back(a[i-1]);
    PayMoney(i-1, cost - a[i-1], Coins);
    Coins.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Flag = false;
    PayMoney(n, k, coins);
    if (!Flag)
        cout << "Cannot change money!";
    return 0;
}
