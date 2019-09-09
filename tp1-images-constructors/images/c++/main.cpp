#include "Image.hpp"

#include <string>
#include <iostream>

using namespace std;

// compile g++ -std=c++11 *.cpp -O2

void maneul_mode() {

    unsigned int h, l;
    cout<<"init img valeur h l: ";
    cin>>h>>l;
    Image img(h, l);

    bool stop = false;


    while(!stop) {

        cout<<"valeur index pour hauteur largeur: ";
        cin>>h>>l;

        int r, g, b;

        cout<<"Pixel format r g b: ";
        cin>>r>>g>>b;

        Pixel p(r, g, b);
        img.setPixel(h, l, p);

        cout<<"1 pour quitter sinon 0: ";
        cin>>stop;
        
    }

    img.print();
}



int main(int argc, char const *argv[])
{
    unsigned int h = 100, l = 100; 
    Image img(h, l);
    Pixel p(230, 123, 21);
    int i_max = 10000;

    for (int k = 0; k < i_max; k++)
    {
        for (unsigned int i = 0; i < h; i++) {
            for (unsigned int j = 0; j < l; j++) {

                img.setPixel(i, j, p);
                
            }
        }
    }
    

    return 0;
}
