#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x;

void DrawTri() {
    for (int i=x; i>1; i--) {
        for (int j=1; j<=i; j++)
            cout << "*";
        cout << '\n';
    }
    cout << "*";
}

int main()
{
    cin >> x;
    DrawTri();
    return 0;
}
