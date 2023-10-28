#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, l = 1;

bool IsPrime(int n){
	if (n<2)
        return false;
    int m = sqrt(n);
	for (int i=2; i<=m; i++) {
        if (n%i==0)
            return false;
	}
	return true;
}

void BuildSSP(int n) {
    int x = 2, l = 1, t = 0;
    while (true) {
        cout << x << " " << t << endl;
        if (l == n) {
            cout << x << endl;
            t = x%10;
            x = x/10;
            l = l - 1;
        }
        t = t + 1;
        if ((t <= 9) && (IsPrime(x*10+t))) {
            x = x*10 + t;
            l = l + 1;
            t = 0;
        }
        else if (t <= 9)
            continue;
        else if ((t > 9) && (l > 0)) {
            t = x%10;
            x = x/10;
            l = l - 1;
        }
        else
            return;
    }
}

int main()
{
    freopen("SUPPRI1.INP", "r", stdin);
    freopen("SUPPRI1.OUT", "w", stdout);
    n = 2;
    BuildSSP(2);
    return 0;
}
