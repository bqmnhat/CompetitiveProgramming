#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct HCN{
    int x1,y1,x2,y2,dt;
}a[101];
int c[101],n; // c la mang qhd voi moi pt c[i] la so hinh chu nhat long nhau dc bao tron boi hcn thu i

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
}

void Area() {
    for (int i=1; i<=n; i++) {
        a[i].dt = (a[i].x2-a[i].x1)*(a[i].y2 - a[i].y1);
    }
}

bool IsAinB(HCN a, HCN b) {
    if ((a.x1 >= b.x1) && (a.x2<=b.x2) && (a.y1>=b.y1) && (a.y2<=b.y2)) {
        return true;
    }
    else
        return false;
}

bool CompareArea(HCN a, HCN b) {
    return (a.dt < b.dt);
}

int MaxColabPre(int p) {
    int ans = 0;
    for (int i=1; i<p; i++) {
        if ((IsAinB(a[i], a[p]) == true) && (c[i] > ans)) {
            ans = c[i];
        }
    }
    return ans;
}

int MaxColab() {
    sort(a+1, a+1+n, CompareArea);
    c[1] = 1;
    int ans = 1;
    for (int i=2; i<=n; i++) {
        c[i] = MaxColabPre(i) + 1;
        if (c[i] > ans) {
            ans = c[i];
        }
    }
    return ans;
}

int main()
{
    freopen("HCN.INP", "r", stdin);
    freopen("HCN.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Area();
    cout << MaxColab();
    return 0;
}
