#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double P, I;

double Solution(double P, double I) {
    if (I == 0)
        return -1;
    return (P/I);
}

int main()
{
    cout << "Hay nhap cong suat (W): ";
    cin >> P;
    cout << "Hay nhap cuong do dong dien (A): ";
    cin >> I;
    double ans = Solution(P, I);
    if (ans == -1)
        cout << "Khong ton tai hieu dien the thoa man";
    else
        cout << "Hieu dien the U (V) la: " << ans;
    return 0;
}
