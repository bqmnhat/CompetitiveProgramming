#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int S;

void Solve() {
    int Near = sqrt(S-1) + 1, i;
    bool Found = false;
    while (Near <= 100) {
        int SNear = Near*Near;
        for (i=Near; i>=0; i--) {
            if ((SNear - 2*(i*(Near - i))) == S) {
                Found = true;
                break;
            }
        }
        if (Found)
            break;
        Near++;
    }
    if (!Found) {
        cout << "Impossible";
        return;
    }
    else {
        cout << "0 " << i << '\n';
        cout << i << ' ' << Near << '\n';
        cout << Near << ' ' << Near - i << '\n';
        cout << Near-i << " 0";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FS.INP", "r", stdin);
    freopen("FS.OUT", "w", stdout);
    cin >> S;
    Solve();
    return 0;
}
