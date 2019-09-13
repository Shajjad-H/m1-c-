#include <iostream>

template <typename T>
void mySwap(T & a, T & b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T myMin(const T & a, const T & b) {
    if(a < b) return a;
    return b;
}

unsigned int len(const char * s) {
    unsigned int l = 0;
    while(s[l] != '\0') l++;
    return l;
}


// template<>
// const char * myMin<const char *>(const char *& a, const char *& b) {
    
//     unsigned int lenToIterate = myMin(len(a), len(b));
    
//     for(unsigned int i = 0; i < lenToIterate; i++) {
        
//         if ( a[i] < b[i] ) return a;
//         if ( a[i] > b[i] ) return b;
        
//     }

//     return a;
// }

// template<>
// char * myMin<const char *>(const char * a, const char * b) {
    
//     unsigned int lenToIterate = myMin(len(a), len(b));
    
//     for(unsigned int i = 0; i < lenToIterate; i++) {
        
//         if ( a[i] < b[i] ) return a;
//         if ( a[i] > b[i] ) return b;
        
//     }

//     return a;
// }


int main() {
   
    
    // std::cout << myMin(5,6) <<std::endl;
    // std::cout << myMin(6,5) <<std::endl;
    // std::cout << myMin("lili","lala") <<std::endl;
    // std::cout << myMin("li","lala") <<std::endl; // 2 arguments de types différents
    // const char * cc="mumu";
    // const char * dd="ma";
    
    // std::cout << myMin(cc,dd) <<std::endl;
    // char ee[5]="toto";
    // char ff[5]="ta"; //tableau de même taille que le précédent
    // std::cout << myMin(ee,ff) <<std::endl;
    // std::cout << myMin("zut",ff) <<std::endl;
    
    return 0;
}