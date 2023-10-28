#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 200000
int n;
struct line {
    int x1, y1, x2, y2;
    double a;
} Li[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> Li[i].x1 >> Li[i].y1 >> Li[i].x2 >> Li[i].y2;
        if (Li[i].y1 > Li[i].y2)
            Li[i].a = double(double(Li[i].y1 - Li[i].y2)/double(Li[i].x1 - Li[i].x2));
        else
            Li[i].a = double(double(Li[i].y2 - Li[i].y1)/double(Li[i].x2 - Li[i].x1));
    }
}

bool CmpA(line x, line y) {
    return (x.a < y.a);
}

int Solution() {
   int ans = 0;
   sort(Li+1, Li+1+n, CmpA);
   for (int i=1; i<=n; i++) {
        if (Li[i].a != Li[i-1].a)
            ans++;
   }
   return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
