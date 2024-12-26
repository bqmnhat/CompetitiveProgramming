#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int NumOfDigits(int x) {
    int ans = 0;
    while (x > 0) {
        ans++;
        x = x/10;
    }
    return ans;
}

int main()
{
    srand(time(0));
    freopen("LAPLAI.INP", "w", stdout);
    int t = 5, n = 200;
    int Test = rand()%t + 1;
    cout << Test << '\n';
    for (int i=1; i<=Test; i++) {
        int A = 1;
        int B = 11;
        while (NumOfDigits(A) != NumOfDigits(B)) {
            A = rand()%n;
            B = rand()%n;
        }
        cout << min(A,B) << ' ' << max(A,B) << '\n';
    }
    return 0;
}
