/*
    De bai:
    Cho biet 3 so a,b,c co la 3 canh cua 1 tam giac hay khong. Neu co la tam giac gi?
*/
#include <iostream>
#include <fstream>
using namespace std;
bool IsDeu(float a, float b,float c) {
    if ((a==b) and (b==c)) {
        return true;
    }
    return false;
}

bool IsCan(float a,float b,float c) {
    if ((a==b) or (b==c) or (a==c)) {
        return true;
    }
    return false;
}

bool IsVuong(float a,float b,float c) {
    if ((a*a == b*b + c*c) or (b*b == a*a + c*c) or (c*c == b*b + a*a)) {
        return true;
    }
    return false;
}

bool IsNhon(float a,float b,float c) {
        if ((a*a < b*b + c*c) and (b*b < a*a + c*c) and (c*c < b*b + a*a)) {
        return true;
    }
    return false;
}

bool IsTu(float a,float b,float c) {
        if ((a*a > b*b + c*c) and (b*b > a*a + c*c) and (c*c > b*b + a*a)) {
        return true;
    }
    return false;
}

int main()
{
    float a,b,c;
    ifstream fi;
    ofstream fo;
    fi.open("BAI1.INP");
    fo.open("BAI1.OUT");
    fi >> a >> b >> c;
    if ((IsVuong(a,b,c)==true) and (IsCan(a,b,c) == true)) {
        fo << "TAM GIAC VUONG CAN";
    }
    else if (IsVuong(a,b,c) == true) {
        fo << "TAM GIAC VUONG";
    }
    else if (IsDeu(a,b,c) == true) {
        fo << "TAM GIAC DEU";
    }
    else if (IsCan(a,b,c) == true) {
        fo << "TAM GIAC CAN";
    }
    else if (IsNhon(a,b,c) == true) {
        fo << "TAM GIAC NHON";
    }
    else if (IsTu(a,b,c) == true) {
        fo << "TAM GIAC TU";
    }
    else fo << "KHONG PHAI TAM GIAC";
    return 0;
}
