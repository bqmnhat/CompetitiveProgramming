#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;
long long a[8];

void Init(long long a[8]) {
    long long S = 0;
    a[0] = 50*14;
    S = S + a[0];
    a[1] = S + 50*15;
    S = S + a[1];
    int i = 2;
    int k = 2;
    while (i<=7) {
        long long c = 50*(14 + k);
        a[i] = S + c;
        S = S + a[i];
        a[i+1] = S + c;
        S = S + a[i+1];
        i = i + 2;
        k = k + 1;
    }
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
