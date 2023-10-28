#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> one[101];
struct Repeating {
    int start, End, itv;
} rep[101];
bool visited[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> one[i].first >> one[i].second;
    for (int j=1; j<=m; j++)
        cin >> rep[j].start >> rep[j].End >> rep[j].itv;
}

void SolveTestCase() {
    for (int i=0; i<=1000000; i++)
        visited[i] = false;
    for (int i=1; i<=n; i++) {
        for (int j=one[i].first; j<one[i].second; j++) {
            if (visited[j]) {
                cout << "CONFLICT" << '\n';
                return;
            }
            visited[j] = true;
        }
    }
    for (int i=1; i<=m; i++) {
        int k = 0;
        while (rep[i].start + rep[i].itv*k <= 1000000){
            for (int j=rep[i].start+rep[i].itv*k; j<rep[i].End+rep[i].itv*k; j++) {
                if (j > 1000000)
                    break;
                if (visited[j]) {
                    cout << "CONFLICT" << '\n';
                    return;
                }
                visited[j] = true;
            }
            k++;
        }
    }
    cout << "NO CONFLICT" << '\n';
}

void Solve() {
    cin >> n >> m;
    while ((n != 0) || (m != 0)) {
        ReadData();
        SolveTestCase();
        cin >> n >> m;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
