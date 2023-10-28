#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TPoint {
    int val, type, id; // type = 0 is check-in day ; type = 1 is check-out day
} a[400001];
int n, RoomNo[200001], la = 0;
bool GotCustomer[200001];

void ReadData() {
    int ai, bi;
    for (int i=1; i<=n; i++) {
        cin >> ai >> bi;
        la++;
        a[la] = {ai, 0, i};
        la++;
        a[la] = {bi, 1, i};
    }
}

bool CmpTPoint(TPoint a, TPoint b) {
    if (a.val == b.val)
        return (a.type < b.type);
    return (a.val < b.val);
}

void Solve() {
    int ans = 0, cur = 0, AvailRoom = 1;
    sort(a+1, a+1+la, CmpTPoint);
    for (int i=1; i<=la; i++) {
        if (a[i].type == 0) {
            cur++;
            ans = max(ans, cur);
            RoomNo[a[i].id] = AvailRoom;
            GotCustomer[AvailRoom] = true;
            AvailRoom++;
            while (GotCustomer[AvailRoom])
                AvailRoom++;
        }
        else {
            cur--;
            GotCustomer[RoomNo[a[i].id]] = false;
            AvailRoom = min(AvailRoom, RoomNo[a[i].id]);
        }
    }
    cout << ans << '\n';
    for (int i=1; i<=n; i++)
        cout << RoomNo[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ROOMSALLOC.INP", "r", stdin);
    freopen("ROOMSALLOC.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
