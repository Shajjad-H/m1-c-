
#include <iostream>

using namespace std;

unsigned long long int facto(unsigned long long int n) {
    unsigned long long int result = 1;
    while(n>0) {
        result *= n;
        n--;
    }

    return result;
}



int main() {

    cout<<facto(5)<<endl;
    cout<<facto(10)<<endl;
    cout<<facto(30)<<endl;
    cout<<facto(50)<<endl;
    cout<<facto(60)<<endl;
    cout<<facto(70)<<endl;
    return 0;
}