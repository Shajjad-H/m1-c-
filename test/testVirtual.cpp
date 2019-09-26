#include <iostream>

using namespace std;

class Employer {
    protected:
        int grade;
    public:
        Employer(): grade(0) {
            cout<<"Employer()"<<endl;
        }
        Employer(int g): grade(g) {
            cout<<"Employer(int g)"<<endl;
        }

        virtual void sayHello() {
            cout<<"Hello Employer"<<endl;
        }
};

class Cadre : public Employer {
    public:
        Cadre() {
            grade = 0;
            cout<<"Cadre()"<<endl;
        }

        Cadre(int g) {
            grade = g;
            cout<<"Cadre(int g)"<<endl;
        }

        void sayHello() {
                cout<<"Hello Cadre"<<endl;
        }
};

void testPoly() {
    
    Cadre c; // C
    Employer & e = c;// E
    Cadre m = 5;//C

    c.sayHello();//Hello Cadre
    e.sayHello();//Hello Cadre
}

int main(int argc, char const *argv[]) {

    testPoly();

    return 0;
}
