#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[60001];

void ReadData() {
    for (int i = 0; i<n; i++)
        cin >> a[i];
}

int Merge(int lo, int mid, int hi) {
    vector<int> Left(a+lo, a+1+mid);
    vector<int> Right(a+mid+1, a+hi+1);
    int nLeft = mid-lo+1, nRight = hi-mid, i = 0, j = 0, k = lo;
    int cnt = 0;
    while ((i < nLeft) && (j < nRight)) {
        if (Left[i] > Right[j])
            a[k++] = Right[j++];
        else {
            a[k++] = Left[i++];
            cnt += j;
        }
    }
    while (i < nLeft) {
        a[k++] = Left[i++];
        cnt += j;
    }
    while (j < nRight)
        a[k++] = Right[j++];
    return cnt;
}

int MergeSort(int lo, int hi)  {
    int InvCnt = 0;
    if (hi > lo) {
        int mid = (lo + hi)/2;
        InvCnt += MergeSort(lo, mid);
        InvCnt += MergeSort(mid+1, hi);
        InvCnt += Merge(lo, mid, hi);
    }
    return InvCnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << MergeSort(0, n-1);
    return 0;
}
