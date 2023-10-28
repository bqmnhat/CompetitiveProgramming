#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[101][101],a1[20002],b1[20002],a2[10001],b2[10001],n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
    }
}

int AreaCovered(){
    int d = 0;
    for (int k = 1; k<=n; k++) {
        for (int i = min(a1[k],a2[k]); i< max(a1[k],a2[k]); i++) {
            for (int j = min(b1[k],b2[k]); j< max(b1[k],b2[k]); j++) {
                if (a[i][j] == false) {
                    d = d + 1;
                    a[i][j] = true;
                }
            }
        }
    }
    return d;
}

void Join() {
    for (int i = n+1; i<=2*n; i++) {
        a1[i] = a2[i-n];
        b1[i] = b2[i-n];
    }
}

int Collapsed() {
    sort(a1+1,a1+1+2*n);
    sort(b1+1,b1+1+2*n);
    return (a1[n+1] - a1[n])*(b1[n+1] - b1[n]);
}

int main()
{
    freopen("HCN.INP", "r", stdin);
    freopen("HCN.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << AreaCovered();
    Join();
    cout << Collapsed();
    return 0;
}
