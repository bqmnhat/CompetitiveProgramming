#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n, InDeg[MaxN+1];
vector<int> g[MaxN+1];

void Init() {
    for (int i=1; i<=n; i++) {
        g[i].clear();
        InDeg[i] = 0;
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ki, v;
        cin >> ki;
        for (int j=1; j<=ki; j++) {
            cin >> v;
            g[i].push_back(v);
            InDeg[v]++;
        }
    }
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
