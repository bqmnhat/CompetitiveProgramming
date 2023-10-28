#include <bits/stdc++.h>

using namespace std;
int n;
double x, y;

struct line{
    double a, b, c;
};
struct pii{
    double x, y;
};

line create(pii a, pii b)
{
    line res;
    res.a = a.y - b.y;
    res.b = b.x - a.x;
    res.c = -res.a*a.x-res.b*a.y;
    return res;
}

double distanceFromPointToLine(pii c, line l)
{
    return abs(l.a*c.x + l.b*c.y + l.c)/sqrt(l.a*l.a+l.b*l.b);
}

signed main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.out","w",stdout);
    cin >> n;
    cin >> x >> y;
    vector<pii> a(n+2);
    for(int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    double res = 10000000;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            pii r = {x,y};
            line l = create(a[i],a[j]);
            res = min(distanceFromPointToLine(r,l), res);
        }
    }
    cout << fixed << setprecision(4) << res;
    return 0;
}
