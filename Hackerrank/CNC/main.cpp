#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int MarkA[MaxN+1];
vector<int> c;
int n, p, q;

void ReadData() {
    int ai;
    for (int i=1; i<=p; i++) {
        cin >> ai;
        MarkA[ai] = i;
    }
    for (int i=1; i<=q; i++) {
        cin >> ai;
        if (MarkA[ai] == 0)
            continue;
        c.push_back(MarkA[ai]);
    }
}

int LIS(const vector<int>& a) {
    int nn = a.size();
    vector<int> lis;
    for (int i=0; i<nn; i++) {
        int j = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if (j == lis.size())
            lis.push_back(a[i]);
        else
            lis[j] = a[i];
    }
    return lis.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> q;
    ReadData();
    cout << LIS(c);
    return 0;
}
