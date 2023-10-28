#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Solve(int n1, int n2) {
    int d = 9, s = 10, a = 45, k = 9; t1 = 0, t2 = 0;
    while (n1 >= d) {
        n1 = n1 - d;
        t1 = t1 + (s - k)*a;
        s = s * 10;
        d = 9*s;
    }

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
