#include <iostream>
#include <fstream>
using namespace std;
bool IsDeu(long long a,b,c) {
    if ((a==b) and (b==c)) {
        return true;
    }
    return false;
}

bool IsCan(long long a,b,c) {
    if ((a==b) or (b==c) or (a==c)) {
        return true;
    }
    return false;
}

bool IsVuong(long long a,b,c) {
    if ((a*a = b*b + c*c) or (b*b = a*a + c*c) or (c*c = b*b + a*a)) {
        return true;
    }
    return false;
}

bool IsNhon(long long a,b,c) {
        if ((a*a < b*b + c*c) or (b*b < a*a + c*c) or (c*c < b*b + a*a)) {
        return true;
    }
    return false;
}

bool IsTu(long long a,b,c) {
        if ((a*a > b*b + c*c) or (b*b > a*a + c*c) or (c*c > b*b + a*a)) {
        return true;
    }
    return false;
}

int main()
{
    long long a,b,c;
    ifstream fi;
    ofstream fo;
    fi.open("BAI1.INP");
    fo.open("BAI1.OUT");
    fi >> a >> b >> c;
    return 0;
}
