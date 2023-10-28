#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long x,y,z;

void Solve() {
    long long k = x+y-1;
    long long v = k*(k-1)/2+1;
    cout << v+y-1 << endl;
    int sum = 0;
    k=0;
    while (sum < z) {
        k++;
        sum+=k;
    }
    v = k*(k-1)/2+1;
    int yy = z-v+1;
    int xx = k+1-yy;
    cout << xx << " " << yy;
}

int main()
{
    freopen("MAPPING.INP", "r", stdin);
    freopen("MAPPING.OUT", "w", stdout);
    cin >> x >> y >> z;
    Solve();
    return 0;
}
