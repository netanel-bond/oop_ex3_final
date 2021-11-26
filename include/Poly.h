
#include <iosfwd> //need to add ostream on cpp file too


#include <vector>
#include "Database.h"


class Rational;

class Poly
{
public:
        Poly(const std::vector<Rational>& rationals); //c-tor for array of rationals

        Poly();  // default c-tor, builds poly with 0 as rational

        Poly(const Rational rat);   //  c-tor for rational as scalar

        Poly(const int coeffes, const Rational);    //  c-tor for an int for the exponent and rational
  


        Poly &operator=(const Poly &);
        Poly & operator+(const Poly& )const ;
        Poly &operator-=(const Poly &);
        Poly &operator*=(const Poly &);
        bool operator==(const Poly &)const;
        bool operator>(const Poly&)const;

        Rational operator[](int);
        Poly operator()(Rational );
private:
        Database m_theData;
};
Poly operator-(const Poly&,const Poly& );
Poly &operator+=(  Poly &,const Poly &);

Poly operator-(const Poly&);

bool operator!=(const Poly&,const Poly&);
bool operator<=(const Poly&,const Poly&);
bool operator>=(const Poly&,const Poly&);
bool operator<(const Poly&,const Poly&);
