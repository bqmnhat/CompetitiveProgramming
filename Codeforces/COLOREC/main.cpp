#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[402][402];

void ReadData() {
    int x, y, c;
    for (int i=1; i<=n; i++) {
        cin >> x >> y >> c;
        a[x+200][y+200] = c;
    }
}

long long Solution() {
    long long ans = 0;
    for (int i=0; i<=401; i++) {
        for (int j=i+1; j<=401; j++) {
            long long t = 0, s = 0;
            for (int k=0; k<=401; k++) {
                if(((a[i][k] == 1) && (a[j][k] == 2)) ||((a[i][k]==2) && (a[j][k] == 1)))
                     t++;
                if(((a[i][k]==4) && (a[j][k] == 3)) || ((a[i][k]==3) && (a[j][k] == 4)))
                     s++;
            }
            ans += (t*s);
            t = s = 0;
            for (int k=0; k<=401; k++) {
                if(((a[i][k] == 1) && (a[j][k] == 3)) ||((a[i][k]==3) && (a[j][k] == 1)))
                     t++;
                if(((a[i][k]==2) && (a[j][k] == 4)) || ((a[i][k]==4) && (a[j][k] == 2)))
                     s++;
            }
            ans += (t*s);
            t = s = 0;
            for (int k=0; k<=401; k++) {
                if(((a[i][k] == 1) && (a[j][k] == 4)) ||((a[i][k]==4) && (a[j][k] == 1)))
                     t++;
                if(((a[i][k]==2) && (a[j][k] == 3)) || ((a[i][k]==3) && (a[j][k] == 2)))
                     s++;
            }
            ans += (t*s);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
