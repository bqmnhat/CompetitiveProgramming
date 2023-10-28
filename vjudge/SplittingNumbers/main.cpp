#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void SolveTestCase() {
    int tmp = n;
    vector<int> OnesPos;
    OnesPos.clear();
    int cnt = 0;
    while (tmp > 0) {
        int Bit = (tmp&1);
        if (Bit == 1)
            OnesPos.push_back(cnt);
        tmp >>= 1;
        cnt++;
    }
    int a = 0, b = 0;
    int l = OnesPos.size();
    for (int i=0; i<l; i++) {
        if (i&1)
            b += (1 << OnesPos[i]);
        else
            a += (1 << OnesPos[i]);
    }
    cout << a << ' ' << b << '\n';
}

void Solve() {
    while ((cin >> n) && (n != 0))
        SolveTestCase();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
