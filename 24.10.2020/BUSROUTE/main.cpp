#include <iostream>
#include <cstdio>
using namespace std;
int a,b,n;

int MinCost() {
    int ans = -1,c,m, x,IndA,IndB;
    for (int i = 1; i<=n; i++) {
        IndA = -1;
        IndB = -1;
        cin >> c >> m;
        for (int j = 1; j<=m; j++) {
            cin >> x;
            if ((x == a) && (IndA == -1))
                IndA = j;
            if (x == b)
                IndB = j;
        }
        if ((IndB > IndA) && (IndB != - 1) && (IndA != -1)) {
            if ((ans == -1) || (c < ans))
                ans = c;
        }
    }
    return ans;
}

int main()
{
    freopen("BUSROUTE.INP", "r", stdin);
    freopen("BUSROUTE.OUT", "w", stdout);
    cin >> a >> b >> n;
    cout << MinCost();
    return 0;
}
