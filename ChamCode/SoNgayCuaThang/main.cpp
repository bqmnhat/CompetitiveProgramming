#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    cin >> t;
     if ((t > 12) || (t < 1))
        cout << "NOT FOUND";
     else
        cout << a[t];
    return 0;
}
