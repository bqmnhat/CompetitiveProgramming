#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int h,w,a[51][51],b[51][51],row[51], col[51], ans = 0, stripe[2501], ls = 0;
bool checked[51][51];

void ReadData() {
    for (int i=1; i<=h; i++) {
        int t = 1;
        for (int j=1; j<=w; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                t = 0;
        }
        row[i] = t;
    }
}

void CheckCol() {
    for (int j=1; j<=w; j++) {
        int t = 1;
        for (int i=1; i<=h; i++) {
            if (a[i][j] == 0)
                t = 0;
        }
        col[j] = t;
    }
}

void DrawCol() {
    for (int j=1; j<=w; j++) {
        bool CanDraw = false;
        if (col[j] == 1) {
            for (int i=1; i<=h; i++) {
                b[i][j] = 1;
                if (checked[i][j] == false)
                    CanDraw = true;
                checked[i][j] = true;
            }
        }
        if (CanDraw == true) {
            ans++;
            ls++;
            stripe[ls] = j;
        }
    }
}

void DrawRow() {
    for (int i=1; i<=h; i++) {
        bool CanDraw = false;
        if (row[i] == 1) {
            for (int j=1; j<=w; j++) {
                b[i][j] = 1;
                if (checked[i][j] == false)
                    CanDraw = true;
                checked[i][j] = true;
            }
        }
        if (CanDraw == true) {
            ans++;
            ls++;
            stripe[ls] = 0-i;
        }
    }
}

void ReDraw() {
    if (h < w) {
        DrawRow();
        DrawCol();
    }
    else {
        DrawCol();
        DrawRow();
    }
}

bool CheckNewDrawing() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

void PrintAns() {
    if (CheckNewDrawing() == true) {
        cout << ans << '\n';
        for (int i=1; i<=ls; i++)
            cout << stripe[i] << " ";
    }
    else
        cout << "-1";
}

int main()
{
    freopen("PICTURE.INP", "r", stdin);
    freopen("PICTURE.OUT", "w", stdout);
    cin >> h >> w;
    ReadData();
    CheckCol();
    ReDraw();
    PrintAns();
    return 0;
}
