#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int k, n;
ll x[MaxN+5], LessSum = 0, GreaterSum = 0;
multiset<ll> Less, Greater;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void InsertNewVal(ll val) {
    ll CurMed = *Less.rbegin();
    if (val > CurMed) {
        Greater.insert(val);
        GreaterSum += val;
        if (Greater.size() > k/2) {
            Less.insert(*Greater.begin());
            LessSum += (*Greater.begin());
            GreaterSum -= (*Greater.begin());
            Greater.erase(Greater.begin());
        }
    }
    else {
        Less.insert(val);
        LessSum += val;
        if (Less.size() > (k+1)/2) {
            Greater.insert(*Less.rbegin());
            GreaterSum += (*Less.rbegin());
            LessSum -= (*Less.rbegin());
            Less.erase(Less.find(*Less.rbegin()));
        }
    }
}

void Erase(ll val) {
    if (Greater.find(val) != Greater.end()) {
        Greater.erase(Greater.find(val));
        GreaterSum -= val;
    }
    else if (Less.find(val) != Less.end()) {
        Less.erase(Less.find(val));
        LessSum -= val;
    }
    if (Less.empty()) {
        Less.insert(*Greater.begin());
        LessSum += (*Greater.begin());
        GreaterSum -= (*Greater.begin());
        Greater.erase(Greater.begin());
    }
}

ll MedVal() {
    if (k&1)
        return (*Less.rbegin());
    return 0;
}

void Solve() {
    Less.insert(x[1]);
    LessSum += x[1];
    for (int i=2; i<=k; i++)
        InsertNewVal(x[i]);
    ll ans = GreaterSum - LessSum + MedVal();
    cout << ans << ' ';
    for (int i=2; i<=n-k+1; i++) {
        if (k == 1) {
            InsertNewVal(x[i+k-1]);
            Erase(x[i-1]);
        }
        else {
            Erase(x[i-1]);
            InsertNewVal(x[i+k-1]);
        }
        ll ans = GreaterSum - LessSum + MedVal();
        cout << ans << ' ';
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
