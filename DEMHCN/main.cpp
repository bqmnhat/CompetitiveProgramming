#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1},
    {0,0,0,0,0,1,1,1},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,0,1,1,1},
    {0,0,0,0,0,1,1,1} };

int findColUp(int matrix[8][8]) {
    int lo = 0, hi = 8 - 1;
    while (lo < hi) {
        int mid = (lo + hi)/2;
        if (matrix[7][mid] < 1)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int findRowUp(int matrix[8][8]) {
    int lo = 0, hi = 8 - 1;
    while (lo < hi) {
        int mid = (lo + hi)/2;
        if (matrix[mid][7] < 1)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    cout << findColUp(a) << " " << findRowUp(a);
    return 0;
}
