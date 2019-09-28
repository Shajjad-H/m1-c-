#include <iostream>

using namespace std;

template<unsigned long long int T>
class Facto {
    public:
        enum { result =  T * (Facto<T-1>::result) };
};


template<>
class Facto<0> {
    public:
        enum { result = 1 };
};

int main() {
    Facto<100>;

    cout<<Facto<10>::result<<endl;
    cout<<Facto<30>::result<<endl;
    cout<<Facto<50>::result<<endl;
    cout<<Facto<60>::result<<endl;
    return 0;
}
