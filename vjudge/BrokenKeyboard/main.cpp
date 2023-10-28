#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
string s;
deque<char> Main, Home, End;

void SolveTestCase() {
    Main.clear();
    Home.clear();
    End.clear();
    int l = s.length();
    bool append = true;
    for (int i=0; i<l; i++) {
        if (s[i] == '[') {
            append = false;
            while (!End.empty()) {
                char tmp = End.front();
                End.pop_front();
                Main.push_back(tmp);
            }
            while (!Home.empty()) {
                char tmp = Home.back();
                Home.pop_back();
                Main.push_front(tmp);
            }
        }
        else if (s[i] == ']') {
            append = true;
            while (!End.empty()) {
                char tmp = End.front();
                End.pop_front();
                Main.push_back(tmp);
            }
            while (!Home.empty()) {
                char tmp = Home.back();
                Home.pop_back();
                Main.push_front(tmp);
            }
        }
        else {
            if (append == true)
                End.push_back(s[i]);
            else
                Home.push_back(s[i]);
        }
    }
    for (auto x: Home)
        cout << x;
    for (auto x: Main)
        cout << x;
    for (auto x: End)
        cout << x;
}

void Solve() {
    while (cin >> s) {
        SolveTestCase();
        cout << '\n';
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
