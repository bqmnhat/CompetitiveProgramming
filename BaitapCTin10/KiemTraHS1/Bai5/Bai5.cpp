#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, a[100001];
priority_queue <pair<int,int>> pq;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

void PrintAns() {
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
}

void Solve() {
    pq.push(make_pair(n,0));
    for (int i=1; i<=k; i++) {
        pair<int,int> subarr = pq.top();
        pq.pop();
        int mid;
        if (subarr.first % 2 == 1) {
            mid = subarr.first/2 + subarr.second;
            a[mid] = i;
            pq.push(make_pair(subarr.first/2, subarr.second));
            pq.push(make_pair(subarr.first/2, mid+1));
        }
        else {
            if (i % 2 == 1) {
                mid = subarr.first/2 + subarr.second;
                a[mid-1] = i;
                pq.push(make_pair(((subarr.first/2)-1), subarr.second));
                pq.push(make_pair(subarr.first/2, mid));
            }
            else {
                mid = subarr.first/2 + subarr.second;
                a[mid] = i;
                pq.push(make_pair(subarr.first/2, subarr.second));
                pq.push(make_pair(((subarr.first/2)-1), mid+1));
            }
        }
    }
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai5.INP", "r", stdin);
    freopen("Bai5.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> k;
    Solve();
    return 0;
}
