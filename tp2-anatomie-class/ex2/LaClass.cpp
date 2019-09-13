#include <iostream>
// g++ -ggdb -std=c++11 LaClass.cpp -o LaClass

using namespace std;

class LaClasse {
   private:
    int l;

   public:
    // Construction, conversion, affectation et destruction
    LaClasse() : l(0) {
        cout << "LaClasse::LaClasse()\n";
    }

    LaClasse(const LaClasse &lc) : l(lc.l) {
        cout << "LaClasse::LaClasse(const LaClasse & )\n";
    }

    LaClasse(int i) : l(i) {
        cout << "LaClasse::LaClasse(int)\n";
    }

    operator bool() const {
        cout << "LaClasse::operator bool() const\n";
        return true;
    }

    ~LaClasse() {
        cout << "~LaClasse::LaClasse()\n";
    }

    const LaClasse &operator=(const LaClasse &c) {
        l = c.l;
        cout << "LaClasse::operator=(const LaClasse &)\n";
        return c;
    }

    // Autre fonction membre
    LaClasse F(LaClasse);

    // Déclaration fonction extérieure amie
    friend ostream &operator<<(ostream &os, const LaClasse &lc);
};

LaClasse F(LaClasse vv) {
    cout << " in F \n";
    return 8;
}

LaClasse LaClasse::F(LaClasse v) {
    cout << " in LaClasse::F \n";
    return ::F(v);
}

ostream &operator<<(ostream &os, const LaClasse &lc) {
    os << " in ostream << LaClasse " << lc.l << endl;
    return os;
}

class LaClasseSpecialisee : public LaClasse {

public:

    LaClasseSpecialisee() : LaClasse() {
        cout<<"LaClasseSpecialisee::LaClasseSpecialisee()"<<endl;
    }

    LaClasseSpecialisee(const LaClasseSpecialisee & lcsp) : LaClasse(lcsp) {
        cout<<"LaClasseSpecialisee::LaClasseSpecialisee(const LaClasseSpecialisee &)"<<endl;
    }

    LaClasseSpecialisee(int i) : LaClasse(i) {
        cout << "LaClasseSpecialisee::LaClasseSpecialisee(int)\n";
    }

    ~LaClasseSpecialisee() {
        cout<<"LaClasseSpecialisee::~LaClasseSpecialisee()"<<endl;
    }

   
    const LaClasseSpecialisee &operator=(const LaClasseSpecialisee & lcsp) {
        
        this->LaClasse::operator=(lcsp);
        cout << "LaClasseSpecialisee::operator=(const LaClasseSpecialisee &)\n";
        return *this;
    }

};

void testLaClass() {
    LaClasse c1;
    LaClasse c2 = LaClasse();
    LaClasse cc1(c1);
    LaClasse cc2 = c1;
    LaClasse cc3 = LaClasse(c1);
    LaClasse cv1(5);
    LaClasse cv2 = 5;
    LaClasse cv3 = LaClasse(5);
    LaClasse cv4 = (LaClasse)5;

    
    cout << endl;
    c1 = cc1;
    cout << endl;
    c2 = 8;
    cout << endl;
    if (cv1) {
        cv1 = F(10);
        cv1 = F(c1);
        cv1 = c1.F(c2);
    }
    cout << "Tableaux \n";
    LaClasse tab[3];
    LaClasse *pc = new LaClasse(tab[0]);
    delete pc;
    cout << "Avant de sortir ... \n";
}

void testLaClasseSpecialisee() {

    LaClasseSpecialisee lcsp; cout<<endl; 
    // LaClasse::LaClasse() LaClasseSpecialisee::LaClasseSpecialisee()

    LaClasseSpecialisee lcsp1 = lcsp; cout<<endl; 
    // LaClasse::LaClasse(const LaClasse & ) LaClasseSpecialisee::LaClasseSpecialisee(const LaClasseSpecialisee &)
    
    LaClasseSpecialisee lcsp2 = LaClasseSpecialisee(); cout<<endl; 
    // LaClasse::LaClasse() LaClasseSpecialisee::LaClasseSpecialisee()

    lcsp2 = lcsp; cout<<endl; 
    // LaClasse::operator=(const LaClasse &) LaClasseSpecialisee::operator=(const LaClasseSpecialisee &)

    LaClasseSpecialisee lcsp3(5); cout<<endl; 
    // LaClasse::LaClasse(int) LaClasseSpecialisee::LaClasseSpecialisee(int)

    LaClasseSpecialisee lcsp4(lcsp); cout<<endl; 
    // LaClasse::LaClasse(const LaClasse & ) LaClasseSpecialisee::LaClasseSpecialisee(const LaClasseSpecialisee &)

    LaClasse lc = lcsp; cout<<endl; 
    // LaClasse::LaClasse(const LaClasse & )

    lc = lcsp1; cout<<endl; 
    // LaClasse::operator=(const LaClasse &)

    LaClasse * plc = new LaClasseSpecialisee(); cout<<endl; 
    // LaClasse::LaClasse() LaClasseSpecialisee::LaClasseSpecialisee()

    delete plc; plc = nullptr; cout<<endl;

    lcsp1 = LaClasseSpecialisee(); cout<<endl;
    // LaClasse::LaClasse()
    // LaClasseSpecialisee::LaClasseSpecialisee()
    // LaClasse::operator=(const LaClasse &)
    // LaClasseSpecialisee::operator=(const LaClasseSpecialisee &)
    // LaClasseSpecialisee::~LaClasseSpecialisee()
    // ~LaClasse::LaClasse()
    
}

void testOptiOuNon() {
    //LaClasse c1;
    // LaClasse c2 = LaClasse();
    // LaClasse c2;
    // LaClasse cc2 = c2;
    LaClasse cv3 = LaClasse(5);
    LaClasse cv4 = (LaClasse)5;

}

int main() {
    testOptiOuNon();
    return 0;
}