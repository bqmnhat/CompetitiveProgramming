#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double Size=10;
    string message(" Valentine vui ve nha Linh ");
    int line = 4;
    if (message.length() % 2 != 0) message += " ";
    for (double x=0; x<Size; x++) {
        for (double y=0; y<=4*Size; y++) {
            double dist1 = sqrt(pow(x-Size,2) + pow(y-Size,2));
            double dist2 = sqrt(pow(x-Size,2) + pow(y-3*Size,2));
            if ((dist1 < Size + 0.2) || (dist2 < Size + 0.2))
                cout << 'v';
            else cout << ' ';
        }
        cout<<'\n';
    }
    for (double x=1;x<2*Size;x++) {
        for(double y=0;y<x;y++)
            cout << " ";
        for (double y=0; y<4*Size + 1 - 2*x; y++) {
            if ((x >= line - 1) && (x <= line + 1)) {
                int id = y - (4*Size - 2*x - message.length()) / 2;
                if (id < message.length() && id >= 0) {
                    if (x == line)
                        cout<<message[id];
                    else
                        cout << ' ';
                }
                else
                    cout << 'v';
            }
            else
                cout << 'v';
        }
        cout<<'\n';
    }
}
