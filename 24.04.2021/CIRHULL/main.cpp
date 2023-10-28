#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int x[1000001], y[1000001], MinX = 1000001, MaxX = 0, MinY = 1000001, MaxY = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] < MinX) {
            MinX = x[i];
        }
        if (x[i] > MaxX) {
            MaxX = x[i];
        }
        if (y[i] < MinY) {
            MinY = y[i];
        }
        if (y[i] > MaxY) {
            MaxY = y[i];
        }
    }
}

void Solve() {
    double ans, a = double(MaxX - MinX)/2, b = double(MaxY - MinY)/2;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
