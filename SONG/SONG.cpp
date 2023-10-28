#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int a,b;
    bool Ascend = false, Descend = false, Mixed = false;
    cin >> a;
    for (int i=1; i<=7; i++) {
        cin >> b;
        if (a<b)
            Ascend = true;
        else if (a>b)
            Descend = true;
        else
            Mixed = true;
        a = b;
    }
    if (((Ascend == true) && (Descend == true)) or (Mixed == true))
        cout << "MIXED";
    else if (Ascend == true)
        cout << "ASCENDING";
    else
        cout << "DESCENDING";
}

int main()
{
    freopen("SONG.INP", "r", stdin);
    freopen("SONG.OUT", "w", stdout);
    Solve();
    return 0;
}
