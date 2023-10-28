#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string sn,sp;
int h[71], k = 1, n;

int Area(int i, int &d) {
    d = i;
    while ((h[d] >= h[i]) && (sn[d] == sn[i]))
        d++;
    d--;
    return h[i]*(d-i+1);
}

void LineArea(int &MaxArea, int &MaxC, int &MaxD, int &Maxk, int &Maxh) {
    int i = 0,d;
    while (i<n) {
        int a = Area(i,d);
        if (a > MaxArea) {
            MaxArea = a;
            MaxC = i;
            MaxD = d;
            Maxh = h[i];
            Maxk = k;
        }
        i = d+1;
    }
}

void MaxRec() {
    int MaxArea = 0, MaxC, MaxD,d, Maxk, Maxh;
    for (int i=0; i<n; i++) {
        h[i] = 1;
    }
    while(cin >> sn) {
        if (k>1) {
            for (int i=0; i<n; i++) {
                if (sn[i] == sp[i]) {
                    h[i]++;
                }
                else {
                    h[i] = 1;
                }
            }
        }
        LineArea(MaxArea, MaxC, MaxD, Maxk, Maxh);
        sp = sn;
        k++;
    }
    cout << MaxArea << endl;
    cout << Maxk - Maxh + 1 << " " << MaxC+1 <<  endl;
    cout << Maxk << " " << MaxD+1;
}

int main()
{
    freopen("CNMAX.INP", "r", stdin);
    freopen("CNMAX.OUT", "w", stdout);
    cin >> n;
    MaxRec();
    return 0;
}
