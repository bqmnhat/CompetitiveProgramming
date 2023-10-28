#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Max = 0, Min = 1e18, cnt = 0;

void ReadData(ll &Max, ll &Min, ll &cnt) {
    ll ai;
    while (cin >> ai) {
        if (ai == 0)
            break;
        if (ai > Max)
            Max = ai;
        if (ai < Min)
            Min = ai;
        cnt++;
    }
}

int main()
{
    ReadData(Max, Min, cnt);
    cout << Max << " " << Min << " " << cnt;
    return 0;
}
