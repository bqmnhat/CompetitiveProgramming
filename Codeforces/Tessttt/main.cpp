#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*class A {
private: int x;
};

class B: protected A {
protected: int y;
};

class C: private B {
    private: int z;
    public:
        C() {
            x = 1;
            y = 2;
            z = 3;
        }
};*/

class Dummy {
public:
    Dummy() {
        cout << "x";
    }
    ~Dummy() {
        cout  << "y";
    }
};
Dummy A;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
