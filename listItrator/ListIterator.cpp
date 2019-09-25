
#include <iostream>

using namespace std;


template<typename T>
class List;

template<typename T>
class Iterator;

template<typename T>
ostream & operator<<(ostream & os, const List<T> &l);


template<typename T>
class Celulle {
    friend List<T>;
    protected:
        Celulle<T> * next;
        T data;
    public:
        
        Celulle(): next(0), data(T()){};

        Celulle(const T & data): data(data){};

        void set_data(const T & data){
            this->data = data;
        }

        const T & get_data() const {
            return this->data;
        }

        Celulle<T> * get_next() const {
            return this->next;
        }
};

template<typename T>
class List {
    protected:
        Celulle<T> * first;

    public:
        typedef Celulle<T> cell_type;
        typedef Iterator<T> iterator;

        List(): first(0) {};
        List(const List &) = delete;

        const Celulle<T> * front() const{
            return this->first;
        }

        void push_front(const T & e) {

            Celulle<T> * tmp = new Celulle<T>(e);
            tmp->next = this->first;
            this->first = tmp;

        }

        size_t size() const {
            size_t s = 0;
            Celulle<T> * tmp = this->first;

            while( tmp ) {
                
                tmp = tmp->next;
                s++;

            }
            return s;
        }

        ~List() {
            Celulle<T> * tmp = this->first;

            while( this->first ) {
                
                tmp = this->first->next;
                delete this->first;

                this->first = tmp;
            }

            this->first = 0;
        }

        friend ostream & operator<< <T>(ostream & os, const List<T> &l);

        iterator begin() const {
            return iterator(this->first);
        }

        // iterator end() const {
        //     return iterator(this->);
        // }


};

template<typename T>
ostream & operator<<(ostream & os, const List<T> &l) {
    
    os << "(";

    Celulle<T> * temp = l.first;
    
    while (temp) {

        os << temp->get_data() << " "; 
        temp = temp->get_next();

    }
    os<< ")" << endl;
    return os;
}

template<typename T>
class Iterator {
    protected:
        Celulle<T> * current;
    public:
        Iterator() = delete;
        Iterator(const Iterator<T> & it): current(it.current) {}
        Iterator(Celulle<T> * cel): current(cel) {}

        Iterator<T> operator++(int) {

            current = current->get_next();

            return *this;
        }

        Celulle<T> & operator*() {

            return *(this->current);
        }
};


#include <cassert>

int main() {

    List<int> l;
    l.push_front(5);
    l.push_front(6);
    l.push_front(7);
    const List<int>::cell_type * i = l.front();
    assert(l.size() == 3);

    List<int>::iterator it = l.begin();
    it++;
    
}