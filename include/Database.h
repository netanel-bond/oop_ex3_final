
#include <vector>;

#include "Rational.h"


class Poly;

class Database {
public:

    ~Database();

    Database(const Rational);                 //  c-tor for scalar
    Database(const int, const Rational);   //  c-tor for scalar and exponent
    Database(const std::vector<Rational> &);     //  c-tor for array of rationals
    Database(const Database &); // copy c-tor
    Database(const Database, const Database);// sum of parameters c-tor
    bool checkEquals(int, int) const;

    Rational rationalMekadem(int i) const;

    int polinom(Rational r) const;

    int getExpo(int) const;

    Rational getRational(int) const;

    //  int setExpo(int);
    //   Rational SetRat(int);
    int getArrSize() const;

    void reAllocate(int);

    void minus();

private:

    int *m_expo;        //  array of exponents
    Rational *m_rat;        //  array of rationals
    int m_arrSize;

    void checkAllocate();

    void insertRest(const Database, int, int);
};