#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long m,n,k;

struct Range{
    int CntAll = 0;
    int CntEqu = 0;
};

Range Cnt(int i, int j, int Max) {
    Range ans;
    long long val = i*i + j*j;
    int r = j+1;
    int c = (int)sqrt(val - r*r);
    while ((r <= Max) && (c>0)) {
        ans.CntAll += c;
        if (r*r + c*c == val) {
            ans.CntEqu += 1;
        }
        r++;
        c = (int)sqrt(val - r*r);
    }
    return ans;
}

Range FindIdx(int row, int col) {
    Range ans;
    ans.CntAll = row*col;
    Range RSide = Cnt(row, col, m);
    Range BSide = Cnt(col, row, n);
    ans.CntAll = ans.CntAll + RSide.CntAll + BSide.CntAll;
    ans.CntEqu = ans.CntEqu + RSide.CntEqu + BSide.CntEqu;
    return ans;
}

long long ValueOfK() {
    long long minCol = 1, maxCol = m, minRow = 1, maxRow = n;
    while (minCol < maxCol) {
        long long mid = (minCol + maxCol)/2;
        Range MaxColIdx = FindIdx(n, mid);
        Range NextColMinIdx = FindIdx(1,mid+1);
        int from = MaxColIdx.CntAll - MaxColIdx.CntEqu;
        int to = MaxColIdx.CntAll;
        if ((k>=from) && (k<=to)) {
            return mid*mid + n*n;
        }
          if ((to < k) || (NextColMinIdx.CntAll <= k)) {
            minCol = mid + 1;
        }
        else if (from > k) {
            maxCol = mid - 1;
        }
    }
    while (minRow < maxRow) {
        long long mid = (minRow + maxRow)/2;
        Range Index = FindIdx(mid , minCol);
        int from = Index.CntAll - Index.CntEqu;
        int to = Index.CntAll;
        if (to < k) {
            minRow = mid + 1;
        }
        else if (from > k) {
            maxRow = mid - 1;
        }
        else {
            return minCol*minCol + mid*mid;
        }
    }
    return minCol*minCol + minRow*minRow;
}

int main()
{
    freopen("NUMORDER.INP", "r", stdin);
    freopen("NUMORDER.OUT", "w", stdout);
    cin >> n >> m >> k;
    cout << ValueOfK();
    return 0;
}
