#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
struct Student {
    int a, b, sum, id;
} x[MaxN+1];
bool Chose[MaxN+1];
int A, B, C, n;
vector<int> StudentsId;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i].a;
    for (int i=1; i<=n; i++) {
        cin >> x[i].b;
        x[i].id = i;
        x[i].sum = x[i].a + x[i].b;
    }
}

bool CmpA(Student a, Student b) {
    if (a.a == b.a)
        return (a.id < b.id);
    return (a.a > b.a);
}

bool CmpB(Student a, Student b) {
    if (a.b == b.b)
        return (a.id < b.id);
    return (a.b > b.b);
}

bool CmpSum(Student a, Student b) {
    if (a.sum == b.sum)
        return (a.id < b.id);
    return (a.sum > b.sum);
}

void Solve() {
    sort(x+1, x+1+n, CmpA);
    for (int i=1, cnt = 0; i<=n && cnt < A; i++) {
        if (!Chose[x[i].id]) {
            Chose[x[i].id] = true;
            StudentsId.push_back(x[i].id);
            cnt++;
        }
    }
    sort(x+1, x+1+n, CmpB);
    for (int i=1, cnt = 0; i<=n && cnt < B; i++) {
        if (!Chose[x[i].id]) {
            Chose[x[i].id] = true;
            StudentsId.push_back(x[i].id);
            cnt++;
        }
    }
    sort(x+1, x+1+n, CmpSum);
    for (int i=1, cnt = 0; i<=n && cnt < C; i++) {
        if (!Chose[x[i].id]) {
            Chose[x[i].id] = true;
            StudentsId.push_back(x[i].id);
            cnt++;
        }
    }
    sort(StudentsId.begin(), StudentsId.end());
    for (int x: StudentsId)
        cout << x << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> B >> C;
    ReadData();
    Solve();
    return 0;
}
