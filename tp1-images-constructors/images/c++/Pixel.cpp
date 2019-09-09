#include "Pixel.hpp"

Pixel::Pixel() {
    this->m_g = 0;
    this->m_b = 0;
    this->m_r = 0;
}

Pixel::Pixel(int r, int g, int b) {
    this->m_r = r;
    this->m_g = g;
    this->m_b = b;
}



int Pixel::r() {
    return this->m_r;
}
int Pixel::g() {
    return this->m_g;
}
int Pixel::b() {
    return this->m_b;
}


void Pixel::setR(int r) {
    this->m_r = r;
}
void Pixel::setG(int g) {
    this->m_g = g;
}
void Pixel::setB(int b) {
    this->m_b = b;
}