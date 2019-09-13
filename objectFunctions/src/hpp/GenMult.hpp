#ifndef __GEN_MULT__SH__HPP__
#define __GEN_MULT__SH__HPP__

class GenMult {
    protected:
        int lastVal;
        int base;
    public:
        GenMult() = delete;
        GenMult(int base);
        int operator()();
};

#endif