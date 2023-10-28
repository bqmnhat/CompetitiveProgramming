#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i == n)
            cout << i;
        else
            cout << i << " ";
    }
    return 0;
}
