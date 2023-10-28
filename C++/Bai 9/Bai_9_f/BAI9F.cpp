#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int length(long long x) {
    int tmp = 0;
    while (x>0) {
        x = x/10;
        tmp = tmp + 1;
    }
    return tmp;
}

int main()
{
    int top = 0;
    int a[19];
    long long n;
    ifstream fi;
    ofstream fo;
    bool ok = true;
    fi.open("BAI9F.INP");
    fo.open("BAI9F.OUT");
    fi >> n;
    int l = length(n), mid = l/2;
    for (int i = 0; i<=mid-1 ; i++) {
        a[i] = n%10;
        n = n/10;
    }
    top = mid-l;
    n = n/(10*(l%2));
    int x;
    while (top>0) {
        x = n%10;
        if (x != a[top]) {
            ok = false;
            break;
        }
        top = top - 1;
        n = n/10;
    }
    if (ok == true) {
        fo << "n la so doi xung";
    }
    else
        fo << "n khong la so doi xung";
    return 0;
}
