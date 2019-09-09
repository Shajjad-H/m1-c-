#ifndef __PIXEL__SH__HPP__
#define __PIXEL__SH__HPP__

class Pixel {

protected:
    int m_r, m_g, m_b;
public:
    Pixel();
    Pixel(int r, int g, int b);
    
    int r();
    int g();
    int b();

    void setR(int r);
    void setG(int g);
    void setB(int b);

};


#endif