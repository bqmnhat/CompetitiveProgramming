#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, l, r, m, dir[256][2][256], MidDir = 0;
deque<char> InsideLR, Left, Right;

void ReadData() {
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i=1; i<l; i++)
        Left.push_back(s[i]);
    for (int i=l; i<=r; i++)
        InsideLR.push_back(s[i]);
    for (int i=r+1; i<=n; i++)
        Right.push_back(s[i]);
}

void MakeDir() {
    dir['L'][0]['L'] = 2;
    dir['L'][0]['R'] = 4;
    dir['L'][1]['L'] = 1;
    dir['L'][1]['R'] = 3;
    dir['R'][0]['L'] = 3;
    dir['R'][0]['R'] = 1;
    dir['R'][1]['L'] = 4;
    dir['R'][1]['R'] = 2;
}

void DoType1(int dequeCmd, char Head) {
    if (dequeCmd == 1) {
        char tmp;
        if (Head == 'L') {
            tmp = Left.back();
            Left.pop_back();
        }
        else {
            tmp = Right.front();
            Right.pop_front();
        }
        InsideLR.push_back(tmp);
    }
    else if (dequeCmd == 2) {
        char tmp;
        if (Head == 'L') {
            tmp = Left.back();
            Left.pop_back();
        }
        else {
            tmp = Right.front();
            Right.pop_front();
        }
        InsideLR.push_front(tmp);
    }
    else if (dequeCmd == 3) {
        char tmp = InsideLR.back();
        InsideLR.pop_back();
        if (Head == 'L')
            Left.push_back(tmp);
        else
            Right.push_front(tmp);
    }
    else {
        char tmp = InsideLR.front();
        InsideLR.pop_front();
        if (Head == 'L')
            Left.push_back(tmp);
        else
            Right.push_front(tmp);
    }
}

void Type1(char Head, char HeadDir) {
    DoType1(dir[Head][MidDir][HeadDir], Head);
}

void Type2() {
    MidDir = 1-MidDir;
}

char Type3(char Head)  {
    if (Head == 'L') {
        if (MidDir == 0)
            return InsideLR.front();
        else
            return InsideLR.back();
    }
    else {
        if (MidDir == 0)
            return InsideLR.back();
        else
            return InsideLR.front();
    }
}

void Solve() {
    MakeDir();
    ReadData();
    string cmd;
    cin >> m;
    cin.ignore();
    for (int i=1; i<=m; i++) {
        getline(cin, cmd);
        if (cmd[0] == 'S') {
            char Head = cmd[2], HeadDir = cmd[4];
            Type1(Head, HeadDir);
        }
        else if (cmd.length() == 1)
            Type2();
        else
            cout << Type3(cmd[2]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    Solve();
    return 0;
}
