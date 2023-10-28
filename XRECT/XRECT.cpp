#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int l[501], r[501], y[1000], ny = 0, n;
struct Rec {
    int x1,y1,x2,y2;
}HCN[501];

bool IsExist(int val, int y[]) {
    for (int i=1; i<=ny; i++) {
        if (val == y[i])
            return true;
    }
    return false;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> HCN[i].x1 >> HCN[i].y2 >> HCN[i].x2 >> HCN[i].y1;
        if (IsExist(HCN[i].y1, y) == false) {
            ny++;
            y[ny] = HCN[i].y1;
        }
        if (IsExist(HCN[i].y2, y) == false) {
            ny++;
            y[ny] = HCN[i].y2;
        }
    }
}

int BinSearch(int val, int lower, int higher) {
    while (lower < higher) {
        int mid = (lower+higher)/2;
        if (y[mid] == val)
            return mid;
        else if (y[mid] < val)
            lower = mid + 1;
        else
            higher = mid - 1;
    }
    return (int)(lower + higher)/2;
}

int ShadedArea() {
    int ans = 0;
    sort(y+1, y+1+ny);
    for (int i=1; i<=n; i++) {
        int lb = BinSearch(HCN[i].y1, 1, ny);
        int ub = BinSearch(HCN[i].y2,1,ny) - 1;
        for (int j=lb; j<=ub; j++) {
            if (((HCN[i].x2 <= r[j]) && (HCN[i].x2 >= l[j])) or ((HCN[i].x1>=l[j]) && (HCN[i].x1<=r[j]))) {
                l[j] = min(HCN[i].x1, l[j]);
                r[j] = max(HCN[i].x2, r[j]);
            }
            else {
                ans = ans + (r[j] - l[j])*(y[j+1] - y[j]);
                r[j] = HCN[i].x2;
                l[j] = HCN[i].x1;
            }
        }
    }
    for (int i=1; i<=ny - 1; i++) {
        ans = ans + (r[i] - l[i])*(y[i+1] - y[i]);
    }
    return ans;
}

int main()
{
    freopen("XRECT.INP", "r", stdin);
    freopen("XRECT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << ShadedArea();
    return 0;
}

