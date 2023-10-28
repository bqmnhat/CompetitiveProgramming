//Thuat toan soi chi Arian
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int v[1001], d[1000], a[1001][1001],n,s,t;

void ReadData() {
    for (int i=1; i<n; i++) {
        for (int j = i+1; j<=n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
}

void PrintAns(int k) {
    cout << k << endl;
    for(int i=1; i<=k; i++){
        cout << v[i] << " ";
    }
}

int Tim(int k) {
    for (int i=1; i<=n; i++) {
        if((a[v[k]][i] == 1) && (d[i] == 0)) {
            return i;
        }
    }
    return -1;
}

void SolveArian() {
    int k = 1,x;
    v[k] = s;
    d[s] = 1;
    while (true) {
        if (k<1) {
            return;
        }
        if (v[k] == t) {
            PrintAns(k);
            return;
        }
        x = Tim(k); // Tim mot duong thong voi phong v[k] ma chua di qua
        if (x>0) {
            k++;
            v[k] = x;
            d[x] = 1;
        }
        else
            k--;
    }
}

int main()
{
    freopen("MECUNG.INP", "r", stdin);
    freopen("MECUNG.OUT", "w", stdout);
    cin >> n >> s >> t;
    ReadData();
    SolveArian();
    return 0;
}
