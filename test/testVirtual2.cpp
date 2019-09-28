#include <iostream>

using namespace std;

class Base {
    public:
        void func1() {
            cout<<"Base::func1()"<<endl;
        }

        void func2() {
            cout<<"Base::func2()"<<endl;
        }


        virtual void func3() {
            cout<<"Base::func3()"<<endl;
        }

};

class Derive : public Base {

    public:

        using Base::func3;

        void func1() {
            cout<<"Derive::func1()"<<endl;
        }
        
        void func2() {
            cout<<"Derive::func2()"<<endl;
        }

        void func3(bool b) {
            cout<<"Derive::func3()"<<endl;
        }
};

class DoubleDerive: public Derive {
    public:
        void func1() {
            cout<<"DoubleDerive::func1()"<<endl;
        }
        
        void func2() {
            cout<<"DoubleDerive::func2()"<<endl;
        }
};


void test1() {
    Base * b = new Derive;
    b->func1();
    b->func2();
    delete b;

    cout<<endl;
    cout<<endl;
}

void test2() {
    Base * b = new DoubleDerive;
    b->func1();
    b->func2();
    delete b;

    cout<<endl;
    cout<<endl;
}

void test3() {
    Derive * b = new DoubleDerive;
    b->func1();
    b->func2();

    delete b;

    cout<<endl;
    cout<<endl;
}

void test4() {
    Derive d;

    d.func3();
}

int main() {
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}