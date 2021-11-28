
#include <iosfwd> //need to add ostream on cpp file too


#include <vector>
#include "Database.h"


class Rational;

class Poly {
public:
    Poly(const std::vector<Rational> &rationals); //c-tor for array of rationals

    Poly();  // default c-tor, builds poly with 0 as rational

    Poly(const Rational rat);   //  c-tor for rational as scalar

    Poly(const int coeffes, const Rational);    //  c-tor for an int for the exponent and rational

    Poly(const Database&);
           int deg() const;

    int getDataSize() const;

    int getExpo(int) const;

    Rational getRational(int) const;

   Poly &operator=(const Poly &);

    Poly& operator+=( const Poly&);
    Poly& operator*=( const Poly&);


   // Poly operator-();
//
     Rational operator[](int) const;

     int operator()(Rational) const;


private:
    Database m_theData;
};

Poly operator+(const Poly&, const Poly&);

Poly operator-(const Poly&,const Poly& );

Poly operator*(const Poly&,const Poly&);


//Poly& operator-=(Poly &,const Poly &);

bool operator==(const Poly&, const Poly&);
bool operator!=(const Poly&, const Poly&);
std::ostream &operator<<(std::ostream &, const Poly &);