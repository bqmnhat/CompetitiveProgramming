#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int k, n;
ll x[MaxN+5];
multiset<ll> Less, Greater;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void InsertNewVal(ll val) {
    ll CurMed = *Less.rbegin();
    if (val > CurMed) {
        Greater.insert(val);
        if (Greater.size() > k/2) {
            Less.insert(*Greater.begin());
            Greater.erase(Greater.begin());
        }
    }
    else {
        Less.insert(val);
        if (Less.size() > (k+1)/2) {
            Greater.insert(*Less.rbegin());
            Less.erase(Less.find(*Less.rbegin()));
        }
    }
}

void Erase(ll val) {
    if (Greater.find(val) != Greater.end())
        Greater.erase(Greater.find(val));
    else if (Less.find(val) != Less.end())
        Less.erase(Less.find(val));
    if (Less.empty()) {
        Less.insert(*Greater.begin());
        Greater.erase(Greater.begin());
    }
}

void Solve() {
    Less.insert(x[1]);
    for (int i=2; i<k; i++)
        InsertNewVal(x[i]);
    for (int i=1; i<=n-k+1; i++) {
        Erase(x[i-1]);
        InsertNewVal(x[i+k-1]);
        cout << (*Less.rbegin()) << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
