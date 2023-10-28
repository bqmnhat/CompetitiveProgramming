#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class A {
    public: virtual void In() = 0;
};

class B : public A{
};

class C: public B {
public: void In() {cout << "C";}
};

int main()
{
    C c;
    B *pb = &c;
    pb->In();
    getchar();
    return 0;
}
