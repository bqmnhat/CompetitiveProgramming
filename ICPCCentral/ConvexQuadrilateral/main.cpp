#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
struct Points {
    ll x,y;
} a[5];

void ReadData() {
    for (int i=0; i<4; i++) {
        cin >> a[i].x >> a[i].y;
    }
}

ll CrossProduct(Points p, Points q, Points r)
{
    ll CRP = ((q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y));
    return CRP;
}

ll orientation(Points p1, Points p2, Points p3) {
    ll val = CrossProduct(p1, p2, p3);
    if(val == 0)
        return 0;
    return val;
}

bool CheckConvex(Points p1, Points p2, Points p3, Points p4)
{
    Points px[4] = {p1, p2, p3, p4} ;
    ll curr = 0, prev = 0;
    for (int i=0; i<4; i++) {
        ll o = orientation(px[i], px[(i+1)%4], px[(i+2)%4]);
        if (o == 0)
            return false;
        curr = CrossProduct(px[i], px[(i+1)%4], px[(i+2)%4]);
        if (curr != 0) {
            if (curr * prev < 0)
                return false;
            else
                prev = curr;
        }
    }
    return true;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        ReadData();
        bool IsConvexQuad = false;
        for (int j1=0; j1<4; j1++) {
            for (int j2 = 0; j2 < 4; j2++)  {
                if (j2 == j1) continue;
                for (int j3 = 0; j3 < 4; j3++) {
                    if ((j3 == j1) || (j3 == j2)) continue;
                        for (int j4 = 0; j4 < 4; j4++) {
                            if ((j4 == j3) || (j4 == j2) || (j4 == j1))
                                continue;
                            IsConvexQuad = CheckConvex(a[j1], a[j2], a[j3], a[j4]);
                            if (IsConvexQuad) {
                                cout << "YES" << '\n';
                                break;
                            }
                        }
                    if (IsConvexQuad)
                        break;
                }
                if (IsConvexQuad)
                    break;
            }
            if (IsConvexQuad)
                break;
        }
        if (!IsConvexQuad)
            cout << "NO" << '\n';
    }
    return 0;
}
