#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, ans[1000], la = 0;
long long a, Dig[10] = {0, 0, 2, 3, 322, 5, 53, 7, 7222, 7332};

void FindAnsForDig(int dig) {
    int tmp = Dig[dig];
    while (tmp > 0) {
        la++;
        ans[la] = tmp%10;
        tmp = tmp/10;
    }
}

void Solve() {
    while (a > 0) {
        int tmp = a%10;
        a = a/10;
        FindAnsForDig(tmp);
    }
    sort(ans+1, ans+1+la, greater<int>());
    for (int i=1; i<=la; i++)
        cout << ans[i];
}

int main()
{
    cin >> n >> a;
    Solve();
    return 0;
}
