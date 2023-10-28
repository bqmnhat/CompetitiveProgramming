#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;

void DrawSolidRec() {
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++)
            cout << "*";
        cout << '\n';
    }
    for (int j=1; j<=m; j++)
        cout << "*";
}

int main()
{
    cin >> n >> m;
    DrawSolidRec();
    return 0;
}
