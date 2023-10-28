#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    char * st1;
    char st2[11] = {'a', 'b', 'c', 'd', 'e', 'f'};

    //for(int i =0; i<10;i++)
    //    st2[i] = 'A';
    //st2[11]='\0';
    st1 = new char[10];
    strcpy(st1,"Dong Den");


    cout<<st2<<endl;
    cout<<st1<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
