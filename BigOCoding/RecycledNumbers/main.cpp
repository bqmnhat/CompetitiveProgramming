#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, a, b, NOD, pow10;

int NumOfDigits(int x) {
    int ans = 0;
    while (x > 0) {
        ans++;
        x = x/10;
    }
    return ans;
}

ll NumOfCycles(int x, int NOD, int pow10, int upper) {
    ll ans = 0;
    int NewX = x;
    while (true) {
        int tmp = NewX%10;
        NewX = NewX/10;
        NewX = tmp*pow10 + NewX;
        if ((NewX <= upper) && (NewX > x)) ans++;
        if (NewX == x) break;
    }
    return ans;
}

ll Solution() {
    ll ans = 0;
    int NOD = NumOfDigits(a);
    pow10 = 1;
    for (int i=1; i<NOD; i++)
        pow10 = pow10*10;
    for (int i=a; i<=b; i++) {
        ans += NumOfCycles(i, NOD, pow10, b);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ':' << ' ' << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
