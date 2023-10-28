#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void PrintAns() {
    for (int i=1; i<=n; i++)
        cout << a[i];
}

void MergeArr(int l, int m, int r)
{
    int i = 1, j = 1, x = l, tmp1 = m-l+1, tmp2 = r-m;
    int Left[tmp1], Right[tmp2];
    for (int i=1; i <= tmp1; i++)
        Left[i] = a[l+i-1];
    for (int i=1; i <= tmp2; i++)
        Right[i] = a[m+i];
    while ((i <= tmp1) && (j <= tmp2)) {
        if (Left[i] <= Right[j]) {
            a[x] = Left[i];
            i++;
        }
        else {
            a[x] = Right[j];
            j++;
        }
        x++;
    }
    while (i <= tmp1) {
        a[x++] = Left[i];
        i++;
    }
    while (j <= tmp2) {
        a[x++] = Right[j];
        j++;
    }
}

void MergeSort(int lo, int hi) {
    if (lo < hi) {
        int m = (lo + hi)/2;
        MergeSort(lo, m);
        MergeSort(m+1, hi);
        MergeArr(lo, m, hi);
    }
}

int main()
{
    cin >> n;
    ReadData();
    MergeSort(1,n);
    PrintAns();
    return 0;
}
