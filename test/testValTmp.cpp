#include <iostream>

using namespace std;

void f1(int && val) {
    cout<<"(int && val)"<<endl;
}

void f1(int & val) {
    cout<<"(int & val)"<<endl;
}


void f_test(int && val) {
    cout<<"f_test (int && val)"<<endl;
    f1(val);
}

void f_test(int & val) {
    cout<<"f_test (int & val)"<<endl;
    f1(val);
}

int main(int argc, char const *argv[])
{
    f_test(10);
    int a = 10;

    cout<<endl;
    f_test(a);
    return 0;
}
