#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long l[5];

void ReadData() {
    for (int i=1; i<=4; i++) {
        cin >> l[i];
    }
}

long long MaxArea() {
    long long ans;
    sort(l+1, l+1+4);
    ans = l[3]*l[1];
    return ans;
}

int main()
{
    freopen("TURTLE.INP", "r", stdin);
    freopen("TURTLE.OUT", "w", stdout);
    ReadData();
    cout << MaxArea();
    return 0;
}
