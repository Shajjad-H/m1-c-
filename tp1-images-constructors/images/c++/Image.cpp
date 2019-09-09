#include "Image.hpp"

#include <iostream>

Image::Image(unsigned int h, unsigned int l) {
    this->m_h = h;
    this->m_l = l;
    this->pixels = new Pixel[h * l];
}

unsigned int Image::getIndex(unsigned int h, unsigned int l) const {
    return (h * this->m_h) + l;
}


Image::~Image() {
    delete[] this->pixels;
    this->pixels = 0;
}

Pixel Image::get(unsigned int x, unsigned int y) const{
    return this->pixels[ this->getIndex(x, y) ];
}

void Image::setPixel(unsigned int x, unsigned int y, const Pixel & p) {
    this->pixels[ this->getIndex(x, y) ] = p;
}

void Image::print() const {
    for(unsigned int h = 0; h < this->m_h; h++) {
        for(unsigned int l = 0; l < this->m_l; l++) {
            Pixel p = this->pixels[this->getIndex(h, l)];
            std::cout<<"("<<(int) p.r()<<" "<< (int) p.g()<< " "<< (int)p.b()<<"), ";
        }
        std::cout<<std::endl;
    }
}


