#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int * t10 = new int[10];

    cout<<*( t10)<<endl;
    cout<<*( t10 -1 )<<endl;

    delete[] t10;
    return 0;
}
