#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int w;

int main()
{
    cin >> w;
    if ((w % 2 == 0) && (w != 2)) {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}
