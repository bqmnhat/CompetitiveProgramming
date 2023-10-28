#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[9];
queue <pair<string,int>> q;
string start = "", destination = "", s1, s2;
pair<string, int> p;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int BFS() {
    for (int i=1; i<=n; i++)
        start = start + char('0' + a[i]);
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++)
        destination = destination + char('0' + a[i]);
    if (start == destination)
        return 0;
    q.push(make_pair(start,0));
    while (!q.empty()) {
        p = q.front();
        s1 = p.first;
        q.pop();
        for (int i = 2; i<=n; i++) {
            s2 = s1;
            reverse(s2.begin(), s2.begin()+i);
            if (s2 == destination)
                return (p.second+1);
            q.push(make_pair(s2, p.second+1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << BFS();
    return 0;
}
