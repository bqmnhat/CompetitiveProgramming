#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

bool IsPrime(long long n) {
    long long m = sqrt(n);
    if (n <= 3) {
        if (n <= 1)
            return false;
        else
            return true;
    }
    else if ((n%2 == 0) || (n%3 == 0)) {
        return false;
    }
    else {
        int i=5, j=7;
        while (i <= m) {
            if ((n%i==0) || (n%j == 0))
                return false;
            i = i + 6;
            j = j + 6;
        }
        return true;
    }
}

int main()
{
    cin >> n;
    if (IsPrime(n) == true)
        cout << "True";
    else
        cout << "False";
    return 0;
}
