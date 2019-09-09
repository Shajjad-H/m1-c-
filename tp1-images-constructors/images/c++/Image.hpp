#ifndef __IMAGE__SH__HPP__
#define __IMAGE__SH__HPP__

#include "Pixel.hpp"

class Image {

protected:
    unsigned int m_h, m_l;
    Pixel * pixels;
    unsigned int getIndex(unsigned int h, unsigned int l) const;
public:
    Image() = delete;
    Image(unsigned int h, unsigned int l);
    ~Image();

    Pixel get(unsigned int h, unsigned int l) const;
    void setPixel(unsigned int h, unsigned int l, const Pixel & p);
    void print() const;
};


#endif