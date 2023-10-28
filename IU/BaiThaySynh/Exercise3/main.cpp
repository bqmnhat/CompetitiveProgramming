#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;

void ReadData() {
    int ai;
    while (cin >> ai)
        a.push_back(ai);
}

void DoubleElement(vector<ll>& List, int id) {
    if (id >= List.size())
        return;
    List[id] = List[id]*2;
    DoubleElement(List, id+1);
}

void PrintList(const vector<ll>& List) {
    for (auto x: List)
        cout << x << ' ';
}

int main()
{
    freopen("EXERCISE3.INP", "r", stdin);
    freopen("EXERCISE3.OUT", "w", stdout);
    ReadData();
    DoubleElement(a, 0);
    PrintList(a);
    return 0;
}
