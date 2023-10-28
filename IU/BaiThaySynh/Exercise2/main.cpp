#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x;
vector<ll> a;

void ReadData() {
    int ai;
    while (cin >> ai)
        a.push_back(ai);
    x = a.back();
    a.pop_back();
}

bool IsXinList(ll x, const vector<ll>& List, int id) {
    if (id >= List.size())
        return false;
    if (List[id] == x)
        return true;
    return IsXinList(x, List, id+1);
}

int main()
{
    freopen("EXERCISE2.INP", "r", stdin);
    freopen("EXERCISE2.OUT", "w", stdout);
    ReadData();
    if (IsXinList(x, a, 0))
        cout << "x Is in List";
    else
        cout << "x is not in List";
    return 0;
}
