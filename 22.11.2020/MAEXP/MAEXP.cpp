#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[1001], sum = 0;

void ReadData(){
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }
}

long long MaxVal() {
    long long  ans = 0, tmp, x;
    for (int p1 = 1; p1 < n; p1++) {
        for (int p2 = p1 + 1; p2<n; p2++) {
            if (p2 - p1 == 1) {
                x = a[p1]*a[p1+1];
                x = x * a[p2+1];
                tmp = sum - a[p1] - a[p1 + 1] - a[p2 + 1] + x;
            }
            else
                tmp = sum - a[p1] - a[p1 + 1] - a[p2] - a[p2 + 1] + (a[p1]*a[p1+1]) + (a[p2]*a[p2+1]);
            if (tmp > ans) {
                ans = tmp;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("MAEXP.INP", "r", stdin);
    freopen("MAEXP.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MaxVal();
    return 0;
}
