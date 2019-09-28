#include <iostream>

using namespace std;

class Employer {
    protected:
        int grade;
    public:
        Employer(const Employer & e) {
            this->grade = e.grade;
            cout<<"Employer(const Employer &)"<<endl;
        }

        Employer(): grade(0) {
            cout<<"Employer()"<<endl;
        }
        Employer(int g): grade(g) {
            cout<<"Employer(int g)"<<endl;
        }

        void sayHello() {
            cout<<"Hello Employer"<<endl;
        }
};

class Cadre : public Employer {
    protected:
        int salary;
    public:
        
        Cadre() {
            grade = 0;
            salary = 500 + grade * 10;
            cout<<"Cadre()"<<endl;
        }

        Cadre(const Cadre & c) {
            this->grade = c.grade;
            this->salary = c.salary;
            cout<<"Cadre(const Cadre &)"<<endl;
        }

        Cadre(int g) {
            grade = g;
            salary = 500 + grade * 10;
            cout<<"Cadre(int g)"<<endl;
        }

        void sayHello() {
                cout<<"Hello Cadre"<<endl;
        }
};

class Directeur : public Cadre {
    protected:
        int suplement;
    public:
        Directeur() {
            grade = 0;
            suplement = grade * 2;
            salary = 500 + grade * 10 + suplement;
            cout<<"Directeur()"<<endl;
        }

        Directeur(int g) {
            grade = g;
            suplement = grade * 2;
            salary = 500 + grade * 10 + suplement;
            cout<<"Directeur(int g)"<<endl;
        }

        void sayHello() {
                cout<<"Hello Directeur: "<< salary <<endl;
        }
};

void testConstructors() {
    Directeur d = 5;
    Directeur d1(d);

    d.sayHello();
    d1.sayHello();
}

void testConstructors2() {
    Cadre d = 5;
    Cadre d1(d);

    d.sayHello();
    d1.sayHello();
}


void testPoly() {
    
    Cadre c; //Cadre
    Employer & e = c;//
    Cadre m = 5;// Cardre (int g)

    c.sayHello();
    e.sayHello();
}

int main(int argc, char const *argv[]) {

    testPoly();
    // testConstructors2();

    return 0;
}
