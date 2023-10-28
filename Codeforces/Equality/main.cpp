#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, b, c;
char tmp1, tmp2;

bool IsCorrect() {
    cin >> a >> tmp1 >> b >> tmp2 >> c;
    return ((a + b) == c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (IsCorrect())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
