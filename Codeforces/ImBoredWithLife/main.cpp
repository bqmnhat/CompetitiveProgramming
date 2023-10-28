#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int A, B;

int Solution() {
    int ans = 1, tmp = min(A, B);
    for (int i=2; i<=tmp; i++)
        ans = ans * i;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    cout << Solution();
    return 0;
}
