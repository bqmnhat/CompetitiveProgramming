#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;

void DrawHollowRec() {
    for (int i=1; i<=m; i++)
        cout << "*";
    cout << '\n';
    for (int i=2; i<=n-1; i++) {
        cout << "*";
        for (int j=1; j<=m-2; j++)
            cout << " ";
        cout << "*" << '\n';
    }
    for (int i=1; i<=m; i++)
        cout << "*";
}

int main()
{
    cin >> n >> m;
    DrawHollowRec();
    return 0;
}
