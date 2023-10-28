#include <iostream>
#include <cstdio>
using namespace std;
int dk,mk,yk,n,d[101],m[101],y[101];

void ReadData(int n, int d[101], int m[101], int y[101]) {
    for (int i=1; i<=n; i++) {
        cin >> d[i] >> m[i] >> y[i];
    }
}

int Age(int d1, int m1, int y1, int d2, int m2, int y2) {
    int ans = 0;
    if (y2 > y1)
        ans = y2 - y1;
    if (m2 < m1)
        ans = ans - 1;
    if ((m2 == m1) && (d2 < d1))
        ans = ans - 1;
    return ans;
}

bool Younger(int i, int j) {
    int a,b,c;
    a = d[i] - d[j];
    b = m[i] - m[j];
    c = y[i] - y[j];
    if (c > 0)
        return true;
    if (c == 0) {
        if ((b>0) || ((b == 0) && (a>=0)))
            return true;
    }
    return false;
}

int PHeir() {
    int ans = -1, agei, ageAns;
    for (int i=1; i<=n; i++) {
        agei = Age(d[i], m[i], y[i], dk, mk, yk);
        if (agei >= 18) {
            if (ans == -1) {
                ans = i;
                ageAns = agei;
            }
            else if (Younger(i,ans)) {
                ans = i;
                ageAns = agei;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("HEIR.INP", "r", stdin);
    freopen("HEIR.OUT", "w", stdout);
    cin >> dk >> mk >> yk >> n;
    ReadData(n,d,m,y);
    cout << PHeir();
    return 0;
}
