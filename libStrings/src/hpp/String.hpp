#ifndef __STRING__SH__HPP__
#define __STRING__SH__HPP__

typedef unsigned long int size_s;
class String {

   protected:
    char * str;
    size_s length;
    size_s reservedLength;
    size_s strLen(const char *) const;
    void replace(const char *);

   public:
    String();
    ~String();
    String(const char *);
    String(const char &);
    String(const String &);

    char at(size_s) const;


    void erase();
    size_s size() const;

    char * c_str() const; 

    const String &operator=(const String &);
    const String &operator=(const char *);

    const String &operator+(const String &);
    const String &operator+(const char *);

    bool operator<(const String &);
    bool operator<(const char &);

    bool operator>(const String &);
    bool operator>(const char &);

    bool operator>=(const String &);
    bool operator>=(const char &);

    bool operator<=(const String &);
    bool operator<=(const char &);

    bool operator==(const String &);
    bool operator==(const char &);

    bool operator!=(const String &);
    bool operator!=(const char &);

    bool operator!();
    bool operator()();
};

#endif