#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, k[MaxN+5];
vector<int> top;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> k[i];
}

int Solution() {
    for (int i=1; i<=n; i++) {
        if (top.size() == 0) {
            top.push_back(k[i]);
            continue;
        }
        int id = upper_bound(top.begin(), top.end(), k[i]) - top.begin();
        if (id == top.size())
            top.push_back(k[i]);
        else
            top[id] = k[i];
    }
    return top.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
