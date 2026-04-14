#include <initializer_list>
#include <iostream>
#include <string>

using namespace std;

class AbstractPair {
public:
    virtual ~AbstractPair() {}
    virtual void show( ostream& os ) const = 0;
    virtual AbstractPair* clone() const = 0;
};

template <typename A, typename B>
class PairImpl : public AbstractPair {
public:
    PairImpl( A a, B b ) : a(a), b(b) {}
    
    void show( ostream& os ) const override {
        os << a << " = " << b;
    }
    AbstractPair* clone() const override {
        return new PairImpl<A, B>( a, b );
    }
private:
    A a;
    B b;
};

class Pair {
public:
    template <typename A, typename B>
    Pair( A a, B b ) {
        p = new PairImpl<A, B>( a, b );
    }

    Pair(const Pair& outro) {
        p = outro.p->clone();
    }

    Pair& operator=(const Pair&outro){
        if (this != &outro){
            delete p;
            p = outro.p->clone();
        }
        return *this;
    }

    ~Pair() {
        delete p;
    }


    void render( ostream& os ) const {
        p->show(os);
    }
private:
    AbstractPair *p;
};

void print( ostream& o, initializer_list<Pair> lista ) {
    for ( const auto& item : lista ) {
        item.render(o);
        o << endl;
    }
}

int main() {
    print( cout, { { "jan", 1 }, { 2, "fev" }, { string( "pi" ), 3.14 } } );

    return 0;  
}