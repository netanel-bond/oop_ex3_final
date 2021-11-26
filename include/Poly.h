
#include <vector>
#include "Database.h"

class Rational;

class Poly
{
    public:

        Poly(const std::vector<Rational>& coeffes); //c-tor for array of rationals

        Poly();  // default c-tor, builds poly with 0 as rational

        Poly(const Rational rat);   //  c-tor for rational as scalar

        Poly(const int coeffes, const Rational);    //  c-tor for an int for the exponent and rational

    private:
        Database m_theData;
};